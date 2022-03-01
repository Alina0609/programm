//
// Created by user on 01.03.2022.
//

#ifndef COURSE_DIGITTOENDREVERS_H
#define COURSE_DIGITTOENDREVERS_H

#include "../../string_/string_.h"

//перенести цифры в конец слова
void digitToEnd(WordDescriptor word);

//Преобразовать строку таким образом, чтобы цифры каждого слова были
//перенесены в конец слова, и изменить порядок следования цифр в слове
//на обратный, буквы перенести в начало слова
void digitToEndRevers(char *str);

#endif //COURSE_DIGITTOENDREVERS_H
