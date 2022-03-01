//
// Created by user on 01.03.2022.
//

#ifndef COURSE_GETCOUNTPALINDROMWORDS_H
#define COURSE_GETCOUNTPALINDROMWORDS_H

#include "../../string_/string_.h"

//возвращает 1 если слово является палиндромом, иначе 0
int isPalindromeWord(WordDescriptor word);

//В данной строке соседние слова разделены запятыми. Определить количество
//слов-палиндромов
int getCountPalindromWords(char *str);

#endif //COURSE_GETCOUNTPALINDROMWORDS_H
