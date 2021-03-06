//
// Created by user on 14.02.2022.
//

#ifndef COURSE_TASKS_H
#define COURSE_TASKS_H

//Дана квадратная матрица, все элементы которой различны. Поменять местами
//строки, в которых находятся максимальный и минимальный элементы
void swapRowsWithMinAndMaxValues(matrix m);

void test_swapRowsWithMinAndMaxValues();

int getMax(int *a, int n);

//Упорядочить строки матрицы по неубыванию наибольших элементов строк
void sortRowsByMaxElement(matrix m);

void test_sortRowsByMaxElement();

int getMin(int *a, int n);

//Дана прямоугольная матрица. Упорядочить столбцы матрицы по неубыванию
//минимальных элементов столбцов:
void sortColsByMinElement(matrix m);

void test_sortColsByMinElement();

//Если данная квадратная матрица 𝐴 симметрична, то заменить 𝐴 ее квадратом
void getSquareOfMatrixIfSymmetric(matrix *m);

void test_getSquareOfMatrixIfSymmetric();

//Дана квадратная матрица. Если среди сумм элементов строк матрицы нет равных, то транспонировать матрицу
void transposeIfMatrixHasNotEqualSumOfRows(matrix m);

void test_transposeIfMatrixHasNotEqualSumOfRows();

//Даны две квадратные матрицы 𝐴 и 𝐵. Определить, являются ли они взаимно обратными
bool isMutuallyInverseMatrices(matrix m1, matrix m2);

void test_isMutuallyInverseMatrices();

//Дана прямоугольная матрица. Назовем псевдодиагональю множество элементов этой матрицы,
//лежащих на прямой, параллельной прямой, содержащей элементы 𝑎𝑖,𝑖. Найти сумму максимальных
// элементов всех псевдодиагоналей данной матрицы
long long findSumOfMaxesOfPseudoDiagonal(matrix m);

void test_findSumOfMaxesOfPseudoDiagonal();

//Дана прямоугольная матрица, все элементы которой различны.
//Найти минимальный элемент матрицы в выделенной области
int getMinInArea(matrix m);

void test_getMinInArea();

// Упорядочить точки по неубыванию их
//расстояний до начала координат
void sortByDistances(matrix m);

void test_sortByDistances();

// Определить количество классов эквивалентных строк данной прямоугольной
//матрицы. Строки считать эквивалентными, если равны суммы их элементов.
int countEqClassesByRowsSum(matrix m);

void test_countEqClassesByRowsSum();

//Дана матрица. Определить 𝑘 – количество "особых" элементов матрицы, считая
//элемент "особым" , если он больше суммы остальных элементов своего столбца
int getNSpecialElement(matrix m);

void test_getNSpecialElement();

position getLeftMin(matrix m);

//Дана квадратная матрица. Заменить предпоследнюю строку матрицы первым
//из столбцов, в котором находится минимальный элемент матрицы
void swapPenultimateRow(matrix m);

void test_swapPenultimateRow();


bool hasAllNonDescendingRows(matrix m);

//Дан массив матриц одного размера. Определить число матриц,
//строки которых упорядочены по неубыванию элементов
int countNonDescendingRowsMatrices(matrix *ms, int nMatrix);

void test_countNonDescendingRowsMatrices();

int countZeroRows(matrix m);

//Дан массив целочисленных матриц. Вывести матрицы,
//имеющие наибольшее число нулевых строк
void printMatrixWithMaxZeroRows(matrix *ms, int nMatrix);

void test_countZeroRows();

//получить норму матрицы ms
int getNorm(matrix ms);

//Дан массив вещественных квадратных матриц. Вывести матрицы с наименьшей
//нормой. В качестве нормы матрицы взять максимум абсолютных величин ее элементов
void printOfMatricesInTheMinNorm(matrix *ms, int nMatrix);

//Дана матрица. Определить 𝑘 – количество "особых" элементов данной матрицы,
// считая элемент "особым" если в строке слева от него находятся меньшие
//элементы, а справа – бoльшие
int getNSpecialElement2(matrix m);

void test_getNSpecialElement2();

//получить скалярное произведение
int getScalarProduct(int *a, int *b, int n);

long long getScalarProductRowAndCol(matrix m, int i, int j);

//*Дана целочисленная квадратная матрица, все элементы которой различны.
//Найти скалярное произведение строки, в которой находится наибольший элемент
//матрицы, на столбец с наименьшим элементом
long long getSpecialScalarProduct(matrix m, int n);

void test_getSpecialScalarProduct();

void tests_matrixTasks();

#endif //COURSE_TASKS_H