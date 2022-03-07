//
// Created by user on 07.03.2022.
//

#include "lastWordsOfTheStr1WhichIsInTheStr2.h"

bool lastWordsOfTheStr1WhichIsInTheStr2(char *str1, char *str2, WordDescriptor *w) {

    if (*str1 == '\0' && *str2 == '\0')
        return false;

    getBagOfWords(&_bag, str2);

    WordDescriptor *_bagEnd = _bag.size + _bag.words;
    char *endStr1 = getEndOfString(str1);

    WordDescriptor lastWord;
    while (getWordRevers(endStr1 - 1, str1 - 1, &lastWord)) {
        for (WordDescriptor *curWord = _bag.words; curWord < _bagEnd; curWord++) {
            if (areWordsEqual(lastWord, *curWord)) {
                *w = lastWord;
                return true;
            }
        }
        endStr1 = lastWord.begin;
    }

    return false;
}