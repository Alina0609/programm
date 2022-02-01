//
// Created by user on 02.02.2022.
//

#ifndef COURSE_VECTOR_H
#define COURSE_VECTOR_H

typedef struct vector {
    int *data; // указатель на элементы вектора
    size_t size; // размер вектора
    size_t capacity; // вместимость вектора
} vector;

#endif //COURSE_VECTOR_H
