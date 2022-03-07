//
// Created by user on 01.03.2022.
//

#include "test_tasks_string.h"


#define ASSERT_STRING(expected, got) assertString(expected, got, \
__FILE__, __FUNCTION__, __LINE__)

void assertString(const char *expected, char *got,
                  char const *fileName, char const *funcName,
                  int line) {
    if (strcmp(expected, got) != 0) {
        fprintf(stderr, " File %s\n", fileName);
        fprintf(stderr, "%s - failed on line %d\n", funcName, line);
        fprintf(stderr, " Expected : \"%s\"\n", expected);
        fprintf(stderr, "Got: \"%s\"\n\n", got);
    } else
        fprintf(stderr, "%s - OK\n", funcName);
}

void test_removeNonLetters1() {
    char str[] = "38r 3dbd f ";

    removeNonLetters(str);

    char res[] = "38r3dbdf";

    ASSERT_STRING(res, str);
}

void test_removeNonLetters2() {
    char str[] = "    ";

    removeNonLetters(str);

    char res[] = "";

    ASSERT_STRING(res, str);
}

void test_removeNonLetters() {
    test_removeNonLetters1();
    test_removeNonLetters2();
}

void test_removeAdjacentEqualLetters1() {
    char str[] = "ddgsiiwwwnx";

    removeAdjacentEqualLetters(str);

    char res[] = "dgsiwnx";

    ASSERT_STRING(res, str);
}

void test_removeAdjacentEqualLetters2() {
    char str[] = "h1gwwbwigw1";

    removeAdjacentEqualLetters(str);

    char res[] = "h1gwbwigw1";

    ASSERT_STRING(res, str);
}

void test_removeAdjacentEqualLetters() {
    test_removeAdjacentEqualLetters1();
    test_removeAdjacentEqualLetters2();
}

void test_removeExtraSpaces1() {
    char str[] = "er    re fs   2 4  c";

    removeExtraSpaces(str);

    char res[] = "er re fs 2 4 c";

    ASSERT_STRING(res, str);
}

void test_removeExtraSpaces2() {
    char str[] = "  fef     fewwd uy     pop";

    removeExtraSpaces(str);

    char res[] = " fef fewwd uy pop";

    ASSERT_STRING(res, str);
}

void test_removeExtraSpaces() {
    test_removeExtraSpaces1();
    test_removeExtraSpaces2();
}

void test_digitToStart1() {
    char str[] = "fhf4f82";
    WordDescriptor word;

    getWord(str, &word);

    digitToStart(word);

    char res[] = "284fhff";

    ASSERT_STRING(res, str);
}

void test_digitToStart2() {
    char str[] = "5gd389he ey63 eh38";
    WordDescriptor word;

    getWord(str, &word);

    digitToStart(word);

    char res[] = "9835gdhe ey63 eh38";

    ASSERT_STRING(res, str);
}

void test_digitToStart() {
    test_digitToStart1();
    test_digitToStart2();
}

void test_digitToEndRevers1() {
    char str[] = "5gd389he ey63 eh38";

    digitToEndRevers(str);

    char res[] = "gdhe9835 ey36 eh83";

    ASSERT_STRING(res, str);
}

void test_digitToEndRevers2() {
    char str[] = "78hdy 7750 6c74clsls";

    digitToEndRevers(str);

    char res[] = "hdy87 0577 cclsls476";

    ASSERT_STRING(res, str);
}

void test_digitToEndRevers() {
    test_digitToEndRevers1();
    test_digitToEndRevers2();
}

void test_getCountPalindromWords1() {
    char str[] = "f33f, rey423, hhhhhh, ui55iu";

    int res = 3;

    assert(res == getCountPalindromWords(str));

    printf("test_getCountPalindromWords1 - OK\n");
}

void test_getCountPalindromWords2() {
    char str[] = "gg543x, 333, jwrrwj, 0p]q";

    int res = 2;

    assert(res == getCountPalindromWords(str));

    printf("test_getCountPalindromWords2 - OK\n");
}

void test_getCountPalindromWords() {
    test_getCountPalindromWords1();
    test_getCountPalindromWords2();
}

void test_replaceNumberWithSpaces1() {
    char str[] = "2mme";

    replaceNumberWithSpaces(str);

    char res[] = "  mme";

    ASSERT_STRING(res, str);
}

void test_replaceNumberWithSpaces2() {
    char str[] = "1pwn3tf 1";

    replaceNumberWithSpaces(str);

    char res[] = " pwn   tf  ";

    ASSERT_STRING(res, str);
}

void test_replaceNumberWithSpaces() {
    test_replaceNumberWithSpaces1();
    test_replaceNumberWithSpaces2();
}

void test_wordsOrdered1() {
    char str[] = "alina daddy mom";
    bool res = true;

    assert(wordOrdered(str) == res);

    printf("test_wordsOrdered1 - OK\n");
}

void test_wordsOrdered2() {
    char str[] = "alina home babby";
    bool res = true;

    assert(!wordOrdered(str) == res);

    printf("test_wordsOrdered2 - OK\n");
}

void test_wordsOrdered() {
    test_wordsOrdered1();
    test_wordsOrdered2();
}

void test_getStringWithMixWords1() {
    char str1[] = "cat work snow";
    char str2[] = "delta dog well";

    char str3[MAX_STRING_SIZE];

    getStringWithMixWords(str1, str2, str3);

    char res[] = "cat delta work dog snow well";

    ASSERT_STRING(res, str3);
}

void test_getStringWithMixWords2() {
    char str1[] = "i you very much";
    char str2[] = "love";

    char str3[MAX_STRING_SIZE];

    getStringWithMixWords(str1, str2, str3);

    char res[] = "i love you very much";

    ASSERT_STRING(res, str3);
}

void test_getStringWithMixWords() {
    test_getStringWithMixWords1();
    test_getStringWithMixWords2();
}

void test_reversString1() {
    char str[] = "cat work snow";
    char res1[] = "snow work cat";
    reversString(str);

    ASSERT_STRING(str, res1);
}

void test_reversString2() {
    char str[] = " sk cat";
    char res1[] = "cat sk";
    reversString(str);

    ASSERT_STRING(str, res1);
}

void test_reversString() {
    test_reversString1();
    test_reversString2();
}

void testAll_getWordBeforeFirstWordWithA() {
WordDescriptor w;

    char s1[] = "";

    assert (getWordBeforeFirstWordWithA(s1, &w) == EMPTY_STRING);

    char s2[] = " ABC";
    assert (getWordBeforeFirstWordWithA(s2, &w)
            == FIRST_WORD_WITH_A);

    char s3[] = "B Q WE YR OW IUWR ";
    assert (getWordBeforeFirstWordWithA(s3, &w) ==
            NOT_FOUND_A_WORD_WITH_A);

    printf("testAll_getWordBeforeFirstWordWithA - OK\n");
}


void test_tasks_string() {
    test_removeNonLetters();
    test_removeAdjacentEqualLetters();
    test_removeExtraSpaces();
    test_digitToStart();
    test_digitToEndRevers();
    test_getCountPalindromWords();
    test_replaceNumberWithSpaces();
    test_wordsOrdered();
    test_getStringWithMixWords();
    test_reversString();
    testAll_getWordBeforeFirstWordWithA();
}
