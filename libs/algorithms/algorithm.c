//
// Created by user on 13.12.2021.
//

#include <stdlib.h>

#include "algorithm.h"

void universalSwap(void *a, void *b, size_t size) {
    char *a1 = a;
    char *b1 = b;
    for (int i = 0; i < size; i++) {
        char t = *a1;
        *a1 = *b1;
        *b1 = t;

        a1++;
        b1++;
    }
}