//
// Created by user on 02.03.2022.
//

#include "replace.h"

void replace(char *source, char *w1, char *w2) {
    size_t w1Size = strlen_(w1);
    size_t w2Size = strlen_(w2);
    WordDescriptor word1 = {w1, w1 + w1Size};
    WordDescriptor word2 = {w2, w2 + w2Size};

    char *readPtr, *recPtr = source;
    if (w1Size >= w2Size) {
        readPtr = source;
    } else {
        copy(source, getEndOfString(source) + 1, _stringBuffer);
        readPtr = _stringBuffer;
    }

    WordDescriptor word;

    while (getWord(readPtr, &word)) {


        }


    }
