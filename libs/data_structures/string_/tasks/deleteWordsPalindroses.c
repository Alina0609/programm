//
// Created by user on 08.03.2022.
//

#include "deleteWordsPalindroses.h"

void deleteWordsPalindroses(char *str) {
    if (*str == '\0')
        return;

    char *begin = str;
    char *end = str;

    WordDescriptor w;

    while (getWord(begin, &w)) {
        if (!isPalindromeWord(w)) {
            end = copy(w.begin, w.end, end);
            *end = ' ';
            end++;
        }
        begin = w.end;
    }

    end -= str != end;
    *end = '\0';
}
