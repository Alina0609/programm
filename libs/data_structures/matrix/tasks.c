//
// Created by user on 14.02.2022.
//

#include <assert.h>
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
        if (a[i] > max)
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
        if (a[i] < min)
            min = a[i];
    }
    return min;
}

void sortColsByMinElement(matrix m) {
    insertionSortColsMatrixByColCriteria(m, getMin);
}

//void test_sortColsByMinElement() {
//    matrix testMatrix = createMatrixFromArray(
//            (int[]) {
//                    5, 8, 0, 9,
//                    2, 3, 7, 5
//            },
//            2, 4);
//    matrix endMatrix = createMatrixFromArray(
//            (int[]) {
//                    0, 5, 8, 9,
//                    7, 2, 3, 5
//            },
//            2, 4);
//
//    sortColsByMinElement(testMatrix);
//
//    assert(twoMatricesEqual(testMatrix, endMatrix));
//
//    freeMemMatrix(&testMatrix);
//    freeMemMatrix(&endMatrix);
//}

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

}

//void test_transposeIfMatrixHasNotEqualSumOfRows

void tests() {
    test_swapRowsWithMinAndMaxValues();
    test_sortRowsByMaxElement();
    //test_sortColsByMinElement();
    test_getSquareOfMatrixIfSymmetric();

}