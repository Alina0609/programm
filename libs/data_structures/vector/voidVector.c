//
// Created by user on 02.02.2022.
//
#include "voidVector.h"

vectorVoid createVectorV(size_t n, size_t baseTypeSize) {
    int *memory = malloc(baseTypeSize * n);
    if (memory == NULL) {
        fprintf(stderr, "bad alloc ");
        exit(1);
    } else
        return (vectorVoid) {memory, 0, n, baseTypeSize};
}

void reserveV(vectorVoid *v, size_t newCapacity) {
    v->data = (int *) realloc(v->data, v->baseTypeSize * newCapacity);
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

void shrinkToFitV(vectorVoid *v) {
    reserveV(v, v->size);
}

void clearV(vectorVoid *v) {
    v->size = 0;
}

void deleteVectorV(vectorVoid *v) {
    free(v->data);
}

