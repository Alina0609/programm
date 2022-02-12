//
// Created by user on 12.02.2022.
//
#include "test_ordered_array_set.h"
#include "ordered_array_set.h"

void test_ordered_array_set_in1() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {1, 2}, 2);
    int value = 1;
    size_t resSet = ordered_array_set_in(&set1, value);
    int index = 0;
    assert (resSet == index);
}

void test_ordered_array_set_in2() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {3, 5, 6, 7, 8, 9}, 6);
    int value = 9;
    size_t resSet = ordered_array_set_in(&set1, value);
    int index = 5;
    assert (resSet == index);
}

void test_ordered_array_set_in3() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {-3, -2, 0, 3, 77}, 5);
    int value = -2;
    size_t resSet = ordered_array_set_in(&set1, value);
    int index = 1;
    assert (resSet == index);
}

void test_ordered_array_set_in() {
    test_ordered_array_set_in1();
    test_ordered_array_set_in2();
    test_ordered_array_set_in3();
}

void test_ordered_array_set_isSubset1() {
    ordered_array_set subset = ordered_array_set_create_from_array((int[]) {0}, 0);
    ordered_array_set set = ordered_array_set_create_from_array((int[]) {0, 3, 4}, 3);

    assert (ordered_array_set_isSubset(subset, set));

    ordered_array_set_delete(subset);
    ordered_array_set_delete(set);
}

void test_ordered_array_set_isSubset2() {
    ordered_array_set subset = ordered_array_set_create_from_array((int[]) {}, 0);
    ordered_array_set set = ordered_array_set_create_from_array((int[]) {}, 0);

    assert (ordered_array_set_isSubset(subset, set));

    ordered_array_set_delete(subset);
    ordered_array_set_delete(set);
}

void test_ordered_array_set_isSubset3() {
    ordered_array_set subset = ordered_array_set_create_from_array((int[]) {8, 9}, 2);
    ordered_array_set set = ordered_array_set_create_from_array((int[]) {1, 2, 3, 6, 8, 9}, 6);

    assert (ordered_array_set_isSubset(subset, set));

    ordered_array_set_delete(subset);
    ordered_array_set_delete(set);
}

void test_ordered_array_set_isSubset() {
    test_ordered_array_set_isSubset1();
    test_ordered_array_set_isSubset2();
    test_ordered_array_set_isSubset3();
}

void test_ordered_array_set_insert1() {
    ordered_array_set set1 = ordered_array_set_create(8);
    ordered_array_set_insert(&set1, 10);
    ordered_array_set_insert(&set1, 8);

    ordered_array_set expectedSet = ordered_array_set_create_from_array((int[]) {8, 10}, 2);
    assert(ordered_array_set_isEqual(set1, expectedSet));

    ordered_array_set_delete(set1);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_insert2() {
    ordered_array_set set1 = ordered_array_set_create(6);
    ordered_array_set_insert(&set1, 6);
    ordered_array_set_insert(&set1, -1);
    ordered_array_set_insert(&set1, 4);

    ordered_array_set expectedSet = ordered_array_set_create_from_array((int[]) {-1, 4, 6}, 3);
    assert(ordered_array_set_isEqual(set1, expectedSet));

    ordered_array_set_delete(set1);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_insert3() {
    ordered_array_set set1 = ordered_array_set_create(5);
    ordered_array_set_insert(&set1, 0);
    ordered_array_set_insert(&set1, -16);
    ordered_array_set_insert(&set1, 20);
    ordered_array_set_insert(&set1, 9);

    ordered_array_set expectedSet = ordered_array_set_create_from_array((int[]) {-16, 0, 9, 20}, 4);
    assert(ordered_array_set_isEqual(set1, expectedSet));

    ordered_array_set_delete(set1);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_insert() {
    test_ordered_array_set_insert1();
    test_ordered_array_set_insert2();
    test_ordered_array_set_insert3();
}

void test_ordered_array_set_deleteElement1() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {3, 4, 5, 7, 10}, 5);
    ordered_array_set_deleteElement(&set1, 10);
    ordered_array_set expectedSet = ordered_array_set_create_from_array((int[]) {3, 4, 5, 7}, 4);

    assert(ordered_array_set_isEqual(set1, expectedSet));

    ordered_array_set_delete(set1);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_deleteElement2() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {-2, -1, 0, 3, 6, 8}, 6);
    ordered_array_set_deleteElement(&set1, 0);
    ordered_array_set expectedSet = ordered_array_set_create_from_array((int[]) {-2, -1, 3, 6, 8}, 5);

    assert (ordered_array_set_isEqual(set1, expectedSet));

    ordered_array_set_delete(set1);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_deleteElement3() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {1, 6, 3, 88}, 4);
    ordered_array_set_deleteElement(&set1, 1);
    ordered_array_set expectedSet = ordered_array_set_create_from_array((int[]) {6, 3, 88}, 3);

    assert (ordered_array_set_isEqual(set1, expectedSet));

    ordered_array_set_delete(set1);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_deleteElement() {
    test_ordered_array_set_deleteElement1();
    test_ordered_array_set_deleteElement2();
    test_ordered_array_set_deleteElement3();
}

void test_ordered_array_set_union1() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {1, 2}, 2);
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {2, 3}, 2);
    ordered_array_set resSet = ordered_array_set_union(set1, set2);
    ordered_array_set expectedSet = ordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);

    assert (ordered_array_set_isEqual(resSet, expectedSet));

    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_union2() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {2, 6, 7, 8}, 4);
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {2, 4, 5, 9, 22}, 5);
    ordered_array_set resSet = ordered_array_set_union(set1, set2);
    ordered_array_set expectedSet = ordered_array_set_create_from_array((int[]) {2, 4, 5, 6, 7, 8, 9, 22}, 8);

    assert (ordered_array_set_isEqual(resSet, expectedSet));


    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_union3() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {-11, 0, 9}, 3);
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {-11, -2, -1, 3}, 4);
    ordered_array_set resSet = ordered_array_set_union(set1, set2);
    ordered_array_set expectedSet = ordered_array_set_create_from_array((int[]) {-11, -2, -1, 0, 3, 9}, 6);

    assert (ordered_array_set_isEqual(resSet, expectedSet));

    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_union() {
    test_ordered_array_set_union1();
    test_ordered_array_set_union2();
    test_ordered_array_set_union3();
}

void test_ordered_array_set_intersection1() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 6, 10}, 6);
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {1, 4, 5, 6}, 4);
    ordered_array_set resSet = ordered_array_set_intersection(set1, set2);
    ordered_array_set expectedSet = ordered_array_set_create_from_array((int[]) {1, 4, 6}, 3);

    assert (ordered_array_set_isEqual(resSet, expectedSet));


    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_intersection2() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {4, 6, 7, 2, -3, 0, 44}, 7);
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {5, 1, 2}, 3);
    ordered_array_set resSet = ordered_array_set_intersection(set1, set2);
    ordered_array_set expectedSet = ordered_array_set_create_from_array((int[]) {2}, 1);
    assert (ordered_array_set_isEqual(resSet, expectedSet));

    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_intersection3() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {-3, 4, 22, 8, 4}, 5);
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {5, 1, 2}, 3);
    ordered_array_set resSet = ordered_array_set_intersection(set1, set2);
    ordered_array_set expectedSet = ordered_array_set_create_from_array((int[]) {}, 0);
    assert (ordered_array_set_isEqual(resSet, expectedSet));

    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_intersection() {
    test_ordered_array_set_intersection1();
    test_ordered_array_set_intersection2();
    test_ordered_array_set_intersection3();
}

void test_ordered_array_set_difference1() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {0, 3, 5, 6}, 4);
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {0, 5, 6, 8, 100}, 5);
    ordered_array_set resSet = ordered_array_set_difference(set1, set2);
    ordered_array_set expectedSet = ordered_array_set_create_from_array((int[]) {3}, 1);

    assert (ordered_array_set_isEqual(resSet, expectedSet));

    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_difference2() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {-1, 0, 8, 9, 33}, 4);
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {-1, 33, 34}, 3);
    ordered_array_set resSet = ordered_array_set_difference(set1, set2);
    ordered_array_set expectedSet = ordered_array_set_create_from_array((int[]) {0, 8, 9}, 3);

    assert (ordered_array_set_isEqual(resSet, expectedSet));

    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_difference3() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {-11, -4, 4, 9, 10}, 5);
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {2, 6, 67, 99}, 4);
    ordered_array_set resSet = ordered_array_set_difference(set1, set2);
    ordered_array_set expectedSet = ordered_array_set_create_from_array((int[]) {-11, -4, 4, 9, 10}, 5);

    assert (ordered_array_set_isEqual(resSet, expectedSet));

    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_difference() {
    test_ordered_array_set_difference1();
    test_ordered_array_set_difference2();
    test_ordered_array_set_difference3();
}

void test_ordered_array_set_symmetricDifference1() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {5, 6, 7, 11, 90}, 5);
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {-4, 5, 7, 9, 33}, 5);
    ordered_array_set resSet = ordered_array_set_symmetricDifference(set1, set2);
    ordered_array_set expectedSet = ordered_array_set_create_from_array((int[]) {-4, 6, 9, 11, 33, 90}, 6);

    assert (ordered_array_set_isEqual(resSet, expectedSet));

    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_symmetricDifference2() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 6, 10}, 6);
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 6, 10}, 6);
    ordered_array_set resSet = ordered_array_set_symmetricDifference(set1, set2);
    ordered_array_set expectedSet = ordered_array_set_create_from_array((int[]) {}, 0);
    assert (ordered_array_set_isEqual(resSet, expectedSet));

    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_symmetricDifference3() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {-12, -11, -1, 0, 4, 3, 7}, 7);
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {-12, -11, -1, 4, 3, 7}, 6);
    ordered_array_set resSet = ordered_array_set_symmetricDifference(set1, set2);
    ordered_array_set expectedSet = ordered_array_set_create_from_array((int[]) {0}, 1);

    assert (ordered_array_set_isEqual(resSet, expectedSet));

    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_symmetricDifference() {
    test_ordered_array_set_symmetricDifference1();
    test_ordered_array_set_symmetricDifference2();
    test_ordered_array_set_symmetricDifference3();
}

void test_ordered_array_set_complement1() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 5}, 5);
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 5, 6, 8}, 7);
    ordered_array_set resSet = ordered_array_set_complement(set1, set2);

    assert(resSet.data[0] == 6);
    assert(resSet.data[1] == 8);
    assert(resSet.size == 2);

    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(resSet);
}

void test_ordered_array_set_complement2() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {8, 9}, 2);
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {-4, -3, 4, 7, 8, 9, 10}, 7);
    ordered_array_set resSet = ordered_array_set_complement(set1, set2);

    assert(resSet.data[0] == -4);
    assert(resSet.data[1] == -3);
    assert(resSet.data[2] == 4);
    assert(resSet.data[3] == 7);
    assert(resSet.data[4] == 10);
    assert(resSet.size == 5);

    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(resSet);
}

void test_ordered_array_set_complement3() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {2, 10, 19}, 3);
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {2, 10, 19, 39, 69}, 5);
    ordered_array_set resSet = ordered_array_set_complement(set1, set2);

    assert(resSet.data[0] == 39);
    assert(resSet.data[1] == 69);
    assert(resSet.size == 2);

    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(resSet);
}

void test_ordered_array_set_complement() {
    test_ordered_array_set_complement1();
    test_ordered_array_set_complement2();
    test_ordered_array_set_complement3();
}

void test_ordered_array_set(){
    test_ordered_array_set_in();
    test_ordered_array_set_isSubset();
    test_ordered_array_set_insert();
    test_ordered_array_set_deleteElement();
    test_ordered_array_set_union();
    test_ordered_array_set_intersection();
    test_ordered_array_set_difference();
    test_ordered_array_set_symmetricDifference();
    test_ordered_array_set_complement();

}