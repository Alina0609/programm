//
// Created by user on 08.02.2022.
//

#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>

#include "matrix.h"
#include "../../algorithms/algorithm.h"

matrix getMemMatrix(int nRows, int nCols) {
    int **values = (int **) malloc(nRows * sizeof(int *));

    if (values == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }

    for (int i = 0; i < nRows; i++) {
        values[i] = (int *) malloc(sizeof(int) * nCols);
        if (values[i] == NULL) {
            fprintf(stderr, "bad alloc");
            exit(1);
        }
    }

    return (matrix) {values, nRows, nCols};
}

matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols) {
    matrix *ms = (matrix *) malloc(nMatrices * sizeof(matrix));
    if (ms == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }

    for (int i = 0; i < nMatrices; i++)
        ms[i] = getMemMatrix(nRows, nCols);

    return ms;
}

void freeMemMatrix(matrix m) {
    for (int i = 0; i < m.nRows; i++)
        free(m.values[i]);

    free(m.values);
}

void freeMemMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++)
        freeMemMatrix(ms[i]);
    free(ms);
}

void inputMatrix(matrix m) {
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            scanf("%d", &m.values[i][j]);
        }
    }
}

void inputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++) {
        inputMatrix(ms[i]);
    }
}

void outputMatrix(matrix m) {
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            printf("%d ", m.values[i][j]);
        }
        printf("\n");
    }
}

void outputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++) {
        outputMatrix(ms[i]);
    }
}

void swapRows(matrix m, int i1, int i2) {
    universalSwap(m.values[i1], m.values[i2], sizeof(int *));
}

void swapColumns(matrix m, int j1, int j2) {
    for (int i = 0; i < m.nRows; i++) {
        universalSwap(&m.values[i][j1], &m.values[i][j2], sizeof(int));
    }
}

