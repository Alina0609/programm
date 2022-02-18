//
// Created by user on 14.02.2022.
//

#include <assert.h>
#include <malloc.h>
#include "matrix.h"
#include "tasks.h"

#include "../../algorithms/array/array.h"

void swapRowsWithMinAndMaxValues(matrix m) {
    position maxPos = getMaxValuePos(m);
    position minPos = getMinValuePos(m);

    swapRows(m, maxPos.rowIndex, minPos.rowIndex);
}

void test_swapRowsWithMinAndMaxValues() {
    matrix testMatrix = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    4, 66, 6,
                    7, 8, 99
            },
            3, 3);

    matrix endMatrix = createMatrixFromArray(
            (int[]) {
                    7, 8, 99,
                    4, 66, 6,
                    1, 2, 3,
            }, 3, 3
    );

    swapRowsWithMinAndMaxValues(testMatrix);

    assert(twoMatricesEqual(testMatrix, endMatrix));

    freeMemMatrix(&testMatrix);
    freeMemMatrix(&endMatrix);
}

int getMax(int *a, int n) {
    int max = a[0];
    for (int i = 0; i < n; i++) {
        if (a[i] >= max)
            max = a[i];
    }
    return max;
}

void sortRowsByMaxElement(matrix m) {
    insertionSortRowsMatrixByRowCriteria(m, getMax);
}

void test_sortRowsByMaxElement() {
    matrix testMatrix = createMatrixFromArray(
            (int[]) {
                    7, 8, 99,
                    4, 66, 6,
                    1, 2, 3,
            }, 3, 3
    );

    sortRowsByMaxElement(testMatrix);

    matrix endMatrix = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    4, 66, 6,
                    7, 8, 99,
            }, 3, 3
    );

    assert(twoMatricesEqual(testMatrix, endMatrix));

    freeMemMatrix(&testMatrix);
    freeMemMatrix(&endMatrix);
}

int getMin(int *a, int n) {
    int min = a[0];
    for (int i = 0; i < n; i++) {
        if (a[i] <= min)
            min = a[i];
    }
    return min;
}

void sortColsByMinElement(matrix m) {
    insertionSortColsMatrixByColCriteria(m, getMin);
}

void test_sortColsByMinElement() {
    matrix testMatrix = createMatrixFromArray(
            (int[]) {
                    5, 8, 0, 9,
                    2, 3, 7, 5
            },
            2, 4);
    matrix endMatrix = createMatrixFromArray(
            (int[]) {
                    0, 5, 8, 9,
                    7, 2, 3, 5
            },
            2, 4);

    sortColsByMinElement(testMatrix);

    assert(twoMatricesEqual(testMatrix, endMatrix));

    freeMemMatrix(&testMatrix);
    freeMemMatrix(&endMatrix);
}

void getSquareOfMatrixIfSymmetric(matrix *m) {
    if (!isSymmetricMatrix(*m))
        return;

    matrix squareMatrix = mulMatrices(*m, *m);

    *m = squareMatrix;
}

void test_getSquareOfMatrixIfSymmetric() {
    matrix testMatrix = createMatrixFromArray(
            (int[]) {
                    1, 4, 3,
                    4, 5, 6,
                    3, 6, 2
            }, 3, 3
    );

    matrix endMatrix = createMatrixFromArray(
            (int[]) {
                    26, 42, 33,
                    42, 77, 54,
                    33, 54, 49
            }, 3, 3
    );

    getSquareOfMatrixIfSymmetric(&testMatrix);

    assert(twoMatricesEqual(testMatrix, endMatrix));

    freeMemMatrix(&testMatrix);
    freeMemMatrix(&endMatrix);
}

void transposeIfMatrixHasNotEqualSumOfRows(matrix m) {
    int *sum = malloc(sizeof(int) * m.nRows);

    for (int i = 0; i < m.nRows; ++i) {
        sum[i] = getSum(m.values[i], m.nCols);
    }

    if (!isUniqueArray(sum, m.nRows))
        return;

    transposeSquareMatrix(m);
}

void test_transposeIfMatrixHasNotEqualSumOfRows() {
    matrix testMatrix = createMatrixFromArray(
            (int[]) {
                    1, 4, 3,
                    8, 5, 6,
                    3, 0, 2
            }, 3, 3
    );

    matrix endMatrix = createMatrixFromArray(
            (int[]) {
                    1, 8, 3,
                    4, 5, 0,
                    3, 6, 2

            }, 3, 3
    );

    transposeIfMatrixHasNotEqualSumOfRows(testMatrix);

    assert(twoMatricesEqual(testMatrix, endMatrix));

    freeMemMatrix(&testMatrix);
    freeMemMatrix(&endMatrix);
}

bool isMutuallyInverseMatrices(matrix m1, matrix m2) {
    if (m1.nRows != m2.nRows || m1.nCols != m2.nCols)
        return false;

    matrix m = mulMatrices(m1, m2);

    return isEMatrix(m);
}

void test_isMutuallyInverseMatrices() {
    matrix testMatrix = createMatrixFromArray(
            (int[]) {
                    1, 3, -5,
                    0, 1, 2,
                    0, 0, 1
            }, 3, 3
    );

    matrix endMatrix = createMatrixFromArray(
            (int[]) {
                    1, -3, 11,
                    0, 1, -2,
                    0, 0, 1

            }, 3, 3
    );

    assert(isMutuallyInverseMatrices(testMatrix, endMatrix));

    freeMemMatrix(&testMatrix);
    freeMemMatrix(&endMatrix);
}

long long findSumOfMaxesOfPseudoDiagonal(matrix m) {

}

void test_findSumOfMaxesOfPseudoDiagonal() {

}

int min(int a, int b) {
    return a > b ? b : a;
}

int getMinInArea(matrix m) {
    position maxPos = getMaxValuePos(m);

    int rIndex = maxPos.rowIndex;
    int leftCols = maxPos.colIndex;
    int rightCols = maxPos.colIndex;
    int minV = m.values[maxPos.rowIndex][maxPos.colIndex];

    while (rIndex >= 0) {
        for (int i = leftCols; i < rightCols; ++i)
            minV = min(m.values[rIndex][i], minV);

        if (leftCols > 0)
            leftCols--;

        if (rightCols + 1 < m.nCols)
            rightCols++;
        rIndex--;
    }
    return minV;
}

void test_getMinInArea() {
    matrix testMatrix = createMatrixFromArray(
            (int[]) {
                    1, 3, -5, 8,
                    4, 11, 2, 7,
                    0, 9, 5, 55
            }, 3, 4
    );

    int res = -5;

    assert(res == getMinInArea(testMatrix));

    freeMemMatrix(&testMatrix);
}

void sortByDistances(matrix m) {
    insertionSortRowsMatrixByRowCriteriaFloat(m, getDistance);
}

void test_sortByDistances() {
    matrix testMatrix = createMatrixFromArray(
            (int[]) {
                    1, 3, 0, 8,
                    4, 1, 2, 7,
                    0, 9, 5, 3
            }, 3, 4
    );

    sortByDistances(testMatrix);

    matrix endMatrix = createMatrixFromArray(
            (int[]) {
                    4, 1, 2, 7,
                    1, 3, 0, 8,
                    0, 9, 5, 3
            }, 3, 4
    );

    assert(twoMatricesEqual(testMatrix, endMatrix));

    freeMemMatrix(&testMatrix);
    freeMemMatrix(&endMatrix);
}

int compare_ints(const void *a, const void *b) {
    int arg1 = *(const int *) a;
    int arg2 = *(const int *) b;
    if (arg1 < arg2)
        return -1;
    if (arg1 > arg2)
        return 1;
    return 0;
}


void tests() {
    test_swapRowsWithMinAndMaxValues();
    test_sortRowsByMaxElement();
    test_sortColsByMinElement();
    test_getSquareOfMatrixIfSymmetric();
    test_transposeIfMatrixHasNotEqualSumOfRows();
    test_isMutuallyInverseMatrices();
    test_findSumOfMaxesOfPseudoDiagonal();
    test_getMinInArea();
    test_sortByDistances();

}