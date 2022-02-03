// Created by user on 02.02.2022.
//
#include <stdio.h>
#include "vector.h"

vector createVector(size_t n) {
    int *memory = malloc(sizeof(int) * n);
    if (memory == NULL) {
        fprintf(stderr, "bad alloc ");
        exit(1);
    } else
        return (vector) {memory, 0, n};
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

void shrinkToFit(vector *v) {
    reserve(v, v->size);
}

void deleteVector(vector *v) {
    free(v->data);
}

bool isEmpty(vector *v) {
    return v->size == 0;
}

bool isFull(vector *v) {
    return v->size == v->capacity;
}

int getVectorValue(vector *v, size_t i) {
    return v->data[i];
}

void pushBack(vector *v, int x) {
    if (isFull(v) && isEmpty(v))
        reserve(v, 1);
    else if (isFull(v))
        reserve(v, 2 * v->capacity);

    v->data[v->size] = x;
    (v->size)++;
}

void popBack(vector *v){
    if(isEmpty(v)){
        fprintf(stderr, "is empty");
        exit(1);
    }
    else
        (v->size)--;
}
