//
// Created by user on 07.03.2022.
//

#include "getStringWithMixWords.h"

void getStringWithMixWords(char *str1, char *str2, char *res) {
    if(*str1 == '\0' && *str2 == '\0')
        return;

    WordDescriptor word1, word2;
    bool isW1Found, isW2Found;
    char *beginSearch1 = str1, *beginSearch2 = str2;

    while ((isW1Found = getWord(beginSearch1, &word1)),
            (isW2Found = getWord(beginSearch2, &word2)),
            isW1Found || isW2Found) {

        if (isW1Found) {
            res = copy(word1.begin, word1.end, res);
            beginSearch1 = word1.end;
            *res = ' ';
            res++;
        }

        if (isW2Found) {
            res = copy(word2.begin, word2.end, res);
            beginSearch2 = word2.end;
            *res = ' ';
            res++;
        }
    }

    *(res - 1) = '\0';
}