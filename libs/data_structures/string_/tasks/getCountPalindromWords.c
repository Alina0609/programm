//
// Created by user on 01.03.2022.
//

#include "getCountPalindromWords.h"

int isPalindromeWord(WordDescriptor word) {
    char *left = word.begin;
    char *right = word.end - 1;

    while (right - left > 0) {
        if (*left != *right)
            return 0;

        left++;
        right--;
    }

    return 1;
}

int getCountPalindromWords(char *str) {
    WordDescriptor word;
    int count = 0;

    if (*str == '\0')
        return count;

    char *lastWriten = str;

    while (getWordSeparatedByComma(lastWriten, &word)) {
        if (isPalindromeWord(word))
            count++;
        lastWriten = word.end + 1;
    }

    return count;
}
