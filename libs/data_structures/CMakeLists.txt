add_library(data_structures
        bitset/bitset.c
        unordered_array_set/unordered_array_set.c
        unordered_array_set/test_unordered_array_set.c
        ordered_array_set/ordered_array_set.c
        ordered_array_set/test_ordered_array_set.c

        vector/vector.c
        vector/test_vector.c
        vector/voidVector.c

        matrix/matrix.c
        matrix/test_matrix.c

        matrix/tasks.c

        string_/string_.c
        string_/test_string_.c
        )

add_subdirectory(string_)
target_link_libraries(data_structures algorithms)



