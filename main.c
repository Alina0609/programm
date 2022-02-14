#include <stdio.h>
#include "libs/data_structures/matrix/test_matrix.h"
#include "libs/data_structures/matrix/matrix.h"
#include "libs/data_structures/matrix/tasks.h"

int main() {
//test_matrix();

    matrix testMatrix = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    4, 66, 6,
                    7, 8, 99
            },
            3, 3);

    swapRowsWithMinAndMaxValues(testMatrix);
    outputMatrix(testMatrix);


    return 0;
}



