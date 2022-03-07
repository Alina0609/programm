//
// Created by user on 07.03.2022.
//

#ifndef COURSE_PRINTWORDBEFOREFIRSTWORDWITHA_H
#define COURSE_PRINTWORDBEFOREFIRSTWORDWITHA_H

#include "../../string_/string_.h"
#include "stdbool.h"
#include "stdio.h"

bool isLetterA(WordDescriptor w);

WordBeforeFirstWordWithAReturnCode getWordBeforeFirstWordWithA(char *s, WordDescriptor *wordBefor);

void printWordBeforeFirstWordWithA(char *s);

#endif //COURSE_PRINTWORDBEFOREFIRSTWORDWITHA_H
