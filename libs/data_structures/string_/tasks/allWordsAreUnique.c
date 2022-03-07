//
// Created by user on 07.03.2022.
//

#include "allWordsAreUnique.h"

bool allWordsAreUnique(char *str) {
    getBagOfWords(&_bag, str);

    WordDescriptor *curWord = _bag.words;
    WordDescriptor *endWord = _bag.words + _bag.size - 1;

    while (curWord < endWord) {
        WordDescriptor *w = curWord + 1;
        while (w <= endWord) {
            if (areWordsEqual(*curWord, *w))
                return false;
            w++;
        }
        curWord++;
    }

    return true;
}
