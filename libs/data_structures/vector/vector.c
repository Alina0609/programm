// Created by user on 02.02.2022.
//
#include <stdio.h>
#include "vector.h"

vector createVector(size_t n) {
    if (malloc(sizeof(int) * n) == NULL) {
        fprintf(stderr, "bad alloc ");
        exit(1);
    } else
        return (vector) {malloc(sizeof(int) * n), 0, n};
}

void reserve(vector *v, size_t newCapacity) {
    v->data = (int *) realloc(v->data, sizeof(int) * newCapacity);
    if (v->data == NULL) {
        fprintf(stderr, "bad alloc ");
        exit(1);
    }
    if (newCapacity == 0)
        v->data = NULL;

    if (newCapacity < v->size)
        v->size = newCapacity;

    v->capacity = newCapacity;
}

void clear(vector *v) {
    v->size = 0;
}

void shrinkToFit(vector *v){
    reserve(v, v->size);
}

void deleteVector(vector *v){
    free(v->data);
}