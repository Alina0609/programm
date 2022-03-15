//
// Created by user on 13.03.2022.
//

#ifndef COURSE_SORT_H
#define COURSE_SORT_H

#include "stdlib.h"
#include "../../algorithms/array/array.h"
#include "memory.h"

//обменная сортировка (пузырьком)
void bubbleSort(int *a, size_t size);

long long getBubbleSortNComp(int *a, size_t size);

//сортировка выбором
void selectionSort(int *a, const size_t size);

long long getSelectionSortNComp(int *a, size_t size);

//сортировка вставками
void insertionSort(int *a, const size_t size);

long long getInsertionSortNComp(int *a, size_t size);

//сортировка расчёской
void combsort(int *a, const size_t size);

long long getCombSortNComp(int *a, size_t size);

//сортировка Шелла
void shellSort(int *a, size_t size);

long long getShellSortNComp(int *a, size_t size);

//цифровая сортировка
void radixSort(int *a, size_t size);

long long getRadixSortNComp(int *a, size_t size);
#endif //COURSE_SORT_H
