//
// Created by user on 08.02.2022.
//

#ifndef COURSE_MATRIX_H
#define COURSE_MATRIX_H

typedef struct matrix {
    int **values; //элементы матрицы
    int nRows; //количество рядов
    int nCols; //количество столбцов
} matrix;

typedef struct position {
    int rowIndex;
    int colIndex;
} position;

//размещает в динамической памяти матрицу размером nRows на nCols
//возвращает матрицу
matrix getMemMatrix(int nRows, int nCols);

//размещает в динамической памяти массив из nMatrices матриц размероми nRows на nCols
//возвращает указатель на нулевую матрицу
matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols);

//освобождает память, выделенную под матрицу m
void freeMemMatrix(matrix m);

//освобождает память, выделенную под хранение массива ms из nMatrices матриц
void freeMemMatrices(matrix *ms, int nMatrices);

//ввод матрицы m
void inputMatrix(matrix m);

//ввод массива ms из nMatrices матриц
void inputMatrices(matrix *ms, int nMatrices);

//вывод матрицы m
void outputMatrix(matrix m);

//вывод массива ms из nMatrices матриц
void outputMatrices(matrix *ms, int nMatrices);

//обмен строк с порядковыми номерами i1 и i2 в матрице m
void swapRows(matrix m, int i1, int i2);

//обмен колонок с порядковыми номерами j1 и j2 в матрице m
void swapColumns(matrix m, int j1, int j2);

#endif //COURSE_MATRIX_H