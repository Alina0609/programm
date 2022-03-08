//
// Created by user on 08.03.2022.
//

#include "deleteWordsPalindroses.h"

void deleteWordsPalindroses(char *str) {
    if (*str == '\0')
        return;

    char *iRead = str;
    char *iWrite = str;

    WordDescriptor w;

    while (getWord(iRead, &w)) {
        if (!isPalindromeWord(w)) {
            iWrite = copy(w.begin, w.end, iWrite);
            *iWrite = ' ';
            iWrite++;
        }
        iRead = w.end;
    }

    iWrite -= str != iWrite;
    *iWrite = '\0';
}
