//
// Created by user on 08.02.2022.
//

#ifndef COURSE_MATRIX_H
#define COURSE_MATRIX_H

typedef struct matrix {
    int **values;
    int nRows;
    int nCols;
} matrix;

typedef struct position {
    int rowIndex;
    int colIndex;
} position;

// размещает в динамической памяти матрицу размером nRows на nCols
// возвращает матрицу
matrix getMemMatrix(int nRows, int nCols);

// размещает в динамической памяти массив из nMatrices матриц размероми nRows на nCols
// возвращает указатель на нулевую матрицу
matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols);

// освобождает память, выделенную под матрицу m
void freeMemMatrix(matrix m);

// освобождает память, выделенную под хранение массива ms из nMatrices матриц
void freeMemArrayOfMatrices(matrix *ms, int nMatrices);

#endif //COURSE_MATRIX_H
