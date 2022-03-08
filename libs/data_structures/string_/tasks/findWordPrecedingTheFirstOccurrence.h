//
// Created by user on 07.03.2022.
//

#ifndef COURSE_FINDWORDPRECEDINGTHEFIRSTOCCURRENCE_H
#define COURSE_FINDWORDPRECEDINGTHEFIRSTOCCURRENCE_H

#include "../../string_/string_.h"
#include "stdbool.h"

int findWordInBag(BagOfWords *bag, WordDescriptor word);

bool bagContainsWord(BagOfWords *bag, WordDescriptor word);

WordPrecedingTheFirstOccurrence findWordPrecedingTheFirstOccurrence(char *str1, char *str2, WordDescriptor *w);

#endif //COURSE_FINDWORDPRECEDINGTHEFIRSTOCCURRENCE_H
