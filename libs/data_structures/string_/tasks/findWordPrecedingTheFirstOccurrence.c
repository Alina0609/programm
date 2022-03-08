//
// Created by user on 07.03.2022.
//

#include "findWordPrecedingTheFirstOccurrence.h"

int findWordInBag(BagOfWords *bag, WordDescriptor word) {
    WordDescriptor *curWord = bag->words;
    WordDescriptor *endWord = bag->words + bag->size;

    while (curWord < endWord) {
        if (areWordsEqual(*curWord, word))
            return curWord - bag->words;

        curWord++;
    }
    return -1;
}

bool bagContainsWord(BagOfWords *bag, WordDescriptor word) {
    return findWordInBag(bag, word) != -1;
}

WordPrecedingTheFirstOccurrence findWordPrecedingTheFirstOccurrence(char *str1, char *str2, WordDescriptor *w) {
    getBagOfWords(&_bag, str2);

    WordDescriptor previousWord;
    if (!getWord(str1, &previousWord))
        return NOT_FOUND;

    if (bagContainsWord(&_bag, previousWord))
        return FIRST_WORD;

    str1 = previousWord.end;
    WordDescriptor curWord;

    while (getWord(str1, &curWord)) {
        if (bagContainsWord(&_bag, curWord)) {
            *w = previousWord;
            return PREVIOUS_WORD_FOUND;
        }

        previousWord = curWord;
        str1 = curWord.end;
    }

    return NOT_FOUND;
}
