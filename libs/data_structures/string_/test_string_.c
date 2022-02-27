//
// Created by user on 26.02.2022.
//

#include "test_string_.h"

void test_find1() {
    char *str = "fh&shwuk2jj4";
    int lenghtStr = 7;
    char *res = str + lenghtStr;

    assert(find(str, str + lenghtStr, 'k') == res);
}

void test_find2() {
    char *str = "sdguuns46edn37";
    int lenghtStr = 14;
    char *res = &str[3];

    assert(find(str, str + lenghtStr, 'u') == res);
}

void test_find() {
    test_find1();
    test_find2();
}

void test_findNonSpace1() {
    char *str = "  6shwjw8";
    char *res = &str[2];

    assert(findNonSpace(str) == res);
}

void test_findNonSpace2() {
    char *str = "   ";
    char *res = &str[3];

    assert(findNonSpace(str) == res);
}

void test_findNonSpace() {
    test_findNonSpace1();
    test_findNonSpace2();
}


void test_findSpace1() {
    char *str = "ge272eh";
    char *res = &str[7];

    assert(findSpace(str) == res);
}

void test_findSpace2() {
    char *str = "gyf g43 4t";
    char *res = &str[3];

    assert(findSpace(str) == res);
}

void test_findSpace() {
    test_findSpace1();
    test_findSpace2();
}

void test_findSpaceReverse1() {
    char *str = "hsd 6e g";
    char *res = &str[6];
    int lenghtStr = 8;

    assert(findSpaceReverse(str + lenghtStr - 1, str) == res);
}

void test_findSpaceReverse2() {
    char *str = "idh234xs";
    char *res = str;
    int lenghtStr = 8;

    assert(findSpaceReverse(str + lenghtStr - 1, str) == res);
}

void test_findSpaceReverse() {
    test_findSpaceReverse1();
    test_findSpaceReverse2();
}

void test_findNonSpaceReverse1() {
    char *str = "  \t  f";
    char *res = &str[5];
    int lenghtStr = 6;

    assert(findNonSpaceReverse(str + lenghtStr - 1, str) == res);
}

void test_findNonSpaceReverse2() {
    char *str = "   ";
    char *res = str;
    int lenghtStr = 3;

    assert(findNonSpaceReverse(str + lenghtStr - 1, str) == res);
}

void test_findNonSpaceReverse() {
    test_findNonSpaceReverse1();
    test_findNonSpaceReverse2();
}

void test_str() {
    test_find();
    test_findNonSpace();
    test_findSpace();
    test_findNonSpaceReverse();
    test_findSpaceReverse();
}