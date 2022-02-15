//
// Created by user on 14.02.2022.
//

#ifndef COURSE_TASKS_H
#define COURSE_TASKS_H

//Дана квадратная матрица, все элементы которой различны. Поменять местами
//строки, в которых находятся максимальный и минимальный элементы
void swapRowsWithMinAndMaxValues(matrix m);

void test_swapRowsWithMinAndMaxValues();

int getMax(int *a, int n);

void sortRowsByMaxElement(matrix m);

void test_sortRowsByMaxElement();

int getMin(int *a, int n);

void sortColsByMinElement(matrix m);

void test_sortColsByMinElement();

void tests();

#endif //COURSE_TASKS_H