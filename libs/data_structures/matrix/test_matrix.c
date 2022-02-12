//
// Created by user on 12.02.2022.
//
#include "matrix.h"
#include <assert.h>
void test_getMemMatrix() {
    int n = 3;
    int testMatrix[][2] = {
            {3, 5},
            {8, 2},
            {0, 1}
    };

    for (int i = 0; i < n; ++i) {
        int nRows = testMatrix[i][0];
        int nCols = testMatrix[i][1];
        matrix m = getMemMatrix(nRows, nCols);

        assert(m.nRows == nRows);
        assert(m.nCols == nCols);

        freeMemMatrix(&m);
    }
}

void test_freeMemMatrix() {
    int n = 4;
    int testMatrix[][2] = {
            {3,  4},
            {7,  9},
            {-2, 9},
            {0,  11}
    };

    for (int i = 0; i < n; i++) {
        int nRows = testMatrix[i][0];
        int nCols = testMatrix[i][1];
        matrix m = getMemMatrix(nRows, nCols);

        freeMemMatrix(&m);

        //assert(m.nCols == 0 && m.nRows == 0);
        //assert(m.values == NULL);
    }
}


void test_swapRows() {
    int n = 3;
    int values[] = {3, 5, 7,
                    1, 9, 0,
                    45, 6, 13};
//matrix *testMatrix;
}

void test_swapColumns() {

}

void test_insertionSortRowsMatrixByRowCriteria() {

}

void test_insertionSortColsMatrixByColCriteria() {

}

void test_isSquareMatrix() {

}

void test_twoMatricesEqual() {

}

void test_isEMatrix() {

}

void test_isSymmetricMatrix() {

}

void test_matrix() {
    test_getMemMatrix();
    test_freeMemMatrix();
//    test_freeMemMatrices();
//    test_inputMatrix();
//    test_inputMatrices();
//    test_outputMatrix();
//    test_outputMatrices();
    test_swapRows();
    test_swapColumns();
    test_insertionSortRowsMatrixByRowCriteria();
    test_insertionSortColsMatrixByColCriteria();
    test_isSquareMatrix();
    test_twoMatricesEqual();
    test_isEMatrix();
    test_isSymmetricMatrix();


}
