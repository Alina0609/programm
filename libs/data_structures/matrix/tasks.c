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
        if (a[i] < max)
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