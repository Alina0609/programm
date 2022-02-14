//
// Created by user on 14.02.2022.
//

#include "matrix.h"
#include "tasks.h"

void swapRowsWithMinAndMaxValues(matrix m){
    position maxPos = getMaxValuePos(m);
    position minPos = getMinValuePos(m);
    swapRows(m, maxPos.rowIndex, minPos.rowIndex);
}


