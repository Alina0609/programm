//
// Created by user on 07.03.2022.
//

#include "printWordBeforeFirstWordWithA.h"

bool isLetterA(WordDescriptor w) {
    char *begin = w.begin;

    while (begin != w.end) {
        if (*begin == 'a' || *begin == 'A')
            return true;

        begin++;
    }
    return false;
}

WordBeforeFirstWordWithAReturnCode getWordBeforeFirstWordWithA(char *s, WordDescriptor *wordBefor) {
    WordDescriptor lastWord;
    char *begin = s;

    if (!getWord(begin, &lastWord))
        return EMPTY_STRING;

    if (isLetterA(lastWord))
        return FIRST_WORD_WITH_A;

    WordDescriptor curWord;
    begin = lastWord.end;

    while (getWord(begin, &curWord) && isLetterA(curWord)) {
        lastWord = curWord;
        begin = curWord.end;
    }

    if (isLetterA(curWord)) {
        *wordBefor = lastWord;
        return WORD_FOUND;
    } else
        return NOT_FOUND_A_WORD_WITH_A;
}

void printWordBeforeFirstWordWithA(char *s) {
    WordDescriptor w;
    WordBeforeFirstWordWithAReturnCode code = getWordBeforeFirstWordWithA(s, &w);

    if (code == WORD_FOUND) {
        char *buff = copy(w.begin, w.end, _stringBuffer);
        *buff = '\0';

        printf("%s", _stringBuffer);
    }
}
