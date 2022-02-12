//
// Created by user on 08.02.2022.
//

#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
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

void freeMemMatrix(matrix *m) {
    for (int i = 0; i < m->nRows; i++)
        free(m->values[i]);
    free(m->values);
}

void freeMemMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++)
        freeMemMatrix((matrix *) ms->values[i]);
    free(ms->values);
}

void inputMatrix(matrix m) {
    for (int rIndex = 0; rIndex < m.nRows; rIndex++) {
        for (int cIndex = 0; cIndex < m.nCols; cIndex++) {
            scanf("%d", &m.values[rIndex][cIndex]);
        }
    }
}

void inputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++) {
        inputMatrix(ms[i]);
    }
}

void outputMatrix(matrix m) {
    for (int rIndex = 0; rIndex < m.nRows; rIndex++) {
        for (int cIndex = 0; cIndex < m.nCols; cIndex++) {
            printf("%d ", m.values[rIndex][cIndex]);
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
    for (int rIndex = 0; rIndex < m.nRows; rIndex++) {
        universalSwap(&m.values[rIndex][j1], &m.values[rIndex][j2], sizeof(int));
    }
}

void insertionSortRowsMatrixByRowCriteria(matrix m, int (*criteria)(int *, int)) {

}

void insertionSortColsMatrixByColCriteria(matrix m, int (*criteria)(int *, int)) {

}

bool isSquareMatrix(matrix m) {
    return m.nRows == m.nCols;
}

bool twoMatricesEqual(matrix m1, matrix m2) {
    if (m1.nRows != m2.nRows || m1.nCols != m2.nCols)
        return false;

    for (int rIndex = 0; rIndex < m1.nRows; rIndex++) {
        for (int cIndex = 0; cIndex < m1.nCols; ++cIndex) {
            if (m1.values[rIndex][cIndex] == m2.values[rIndex][cIndex])
                return true;
        }
    }
    return false;
}

bool isEMatrix(matrix m) {
    if (!isSquareMatrix(m))
        return false;

    for (int rIndex = 0; rIndex < m.nRows; rIndex++) {
        for (int cIndex = 0; cIndex < m.nCols; ++cIndex) {
            if (rIndex == cIndex && m.values[rIndex][cIndex] != 1
                || rIndex != cIndex && m.values[rIndex][cIndex] != 0)
                return false;
        }
    }
    return true;
}

bool isSymmetricMatrix(matrix m) {
    if (!isSquareMatrix(m))
        return false;

    for (int rIndex = 0; rIndex < m.nRows; rIndex++) {
        for (int cIndex = 0; cIndex < m.nCols; cIndex++) {
            int rowsIndex = cIndex;
            int colsIndex = rIndex;

            if (m.values[rIndex][cIndex] == m.values[rowsIndex][colsIndex])
                return true;
        }
    }
    return false;
}

void transposeSquareMatrix(matrix m) {
    assert(isSquareMatrix(m));

    for (int rIndex = 0; rIndex < m.nRows; ++rIndex) {
        for (int cIndex = 0; cIndex < m.nCols; ++cIndex) {
            if(rIndex != cIndex)
                universalSwap(&m.values[rIndex][cIndex], &m.values[cIndex][rIndex], sizeof(int));
        }
    }
}

position getMinValuePos(matrix m) {
    position minValuePos = {0, 0};

    for (int rIndex = 0; rIndex < m.nRows; rIndex++) {
        for (int cIndex = 0; cIndex < m.nCols; cIndex++) {
            position currentPos = {rIndex, cIndex};
            if (m.values[currentPos.rowIndex][currentPos.colIndex] <
                m.values[minValuePos.rowIndex][minValuePos.colIndex])
                minValuePos = currentPos;
        }
    }
    return minValuePos;
}

position getMaxValue(matrix m) {
    position maxValuePos = {0, 0};

    for (int rIndex = 0; rIndex < m.nRows; rIndex++) {
        for (int cIndex = 0; cIndex < m.nCols; cIndex++) {
            position currentPos = {rIndex, cIndex};
            if (m.values[currentPos.rowIndex][currentPos.colIndex] >
                m.values[maxValuePos.rowIndex][maxValuePos.colIndex])
                maxValuePos = currentPos;
        }
    }
    return maxValuePos;
}