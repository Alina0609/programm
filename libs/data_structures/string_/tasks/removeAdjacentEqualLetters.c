//
// Created by user on 01.03.2022.
//

#include <memory.h>
#include "removeAdjacentEqualLetters.h"

void removeAdjacentEqualLetters(char *s) {
    if (*s)
        return;

    char *lastWriten = s;
    s++;

    while (*s) {
        if (*lastWriten != *s) {
            lastWriten++;
            memcpy(lastWriten, s, sizeof(char));
        }
        s++;
    }
    lastWriten++;
    *lastWriten = '\0';
}