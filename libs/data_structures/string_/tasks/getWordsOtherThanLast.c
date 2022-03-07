//
// Created by user on 07.03.2022.
//

#include "getWordsOtherThanLast.h"

void getWordsOtherThanLast(char *str) {
    WordDescriptor curWord, lastWord;

    char *endBuff = copy(str, getEndOfString(str), _stringBuffer);
    *endBuff = '\0';

    if (!getWordRevers(endBuff - 1, _stringBuffer - 1, &lastWord))
        return;

    char *beginBuff = _stringBuffer;
    char *endStr = str;

    while (getWord(beginBuff, &curWord)) {
        if (!areWordsEqual(lastWord, curWord)) {
            endStr = copy(curWord.begin, curWord.end, endStr);
            *endStr = ' ';
            endStr++;
        }

        beginBuff = curWord.end;
    }
    endStr -= str != endStr;
    *endStr = '\0';
}