//
// Created by user on 01.03.2022.
//

#include "test_tasks_string.h"
#include "removeAdjacentEqualLetters.h"

#define ASSERT_STRING(expected, got) assertString(expected, got, \
__FILE__, __FUNCTION__, __LINE__)

void assertString(const char *expected, char *got,
                  char const *fileName, char const *funcName,
                  int line) {
    if (strcmp(expected, got) != 0) {
        fprintf(stderr, " File %s\n", fileName);
        fprintf(stderr, "%s - failed on line %d\n", funcName, line);
        fprintf(stderr, " Expected : \"%s \"\n", expected);
        fprintf(stderr, "Got: \"%s\"\n\n", got);
    } else
        fprintf(stderr, "%s - OK\n", funcName);
}

void test_removeNonLetters1() {
    char str[] = "38r 3dbd f ";

    removeNonLetters(str);

    char res[]= "38r3dbdf";

    ASSERT_STRING(res, str);
}

void test_removeNonLetters2() {
    char str[] = "    ";

    removeNonLetters(str);

    char res[]= "";

    ASSERT_STRING(res, str);
}

void test_removeNonLetters() {
    test_removeNonLetters1();
    test_removeNonLetters2();
}

void test_removeAdjacentEqualLetters1(){
    char str[] = "ddgsiiwwwnx";

    removeAdjacentEqualLetters(str);

    char res[]= "dgsiwnx";

    ASSERT_STRING(res, str);
}

void test_removeAdjacentEqualLetters2(){
    char str[] = "h1gwwbwigw1";

    removeAdjacentEqualLetters(str);

    char res[]= "h1gwbi";

    ASSERT_STRING(res, str);
}

void test_removeAdjacentEqualLetters(){
    test_removeAdjacentEqualLetters1();
    test_removeAdjacentEqualLetters2();
}

void test_tasks_string() {
    test_removeNonLetters();
test_removeAdjacentEqualLetters();
}
