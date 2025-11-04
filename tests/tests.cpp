#include <gtest/gtest.h>
#include <vector>
#include <cstdlib>
#include "src/parsort.h"
#include "src/seqsort.h"

std::vector<int> generate_random_vector(size_t size) {
    std::vector<int> vec(size);
    for (size_t i = 0; i < size; i++) {
        vec[i] = std::rand() % 1000000;
    }
    return vec;
}

std::vector<int> generate_sorted_vector(size_t size) {
    std::vector<int> vec(size);
    for (size_t i = 0; i < size; i++) {
        vec[i] = i;
    }
    return vec;
}

std::vector<int> generate_reversed_vector(size_t size) {
    std::vector<int> vec(size);
    for (size_t i = 0; i < size; i++) {
        vec[i] = size - i;
    }
    return vec;
}

void check_sorted(const std::vector<int>& vec) {
    for (size_t i = 0; i < vec.size() - 1; i++) {
        EXPECT_LE(vec[i], vec[i + 1]);
    }
}

TEST(Tests, SequentialSorting) {
    std::vector<int> vec = generate_random_vector(1000000);
    seqsort(vec);
    check_sorted(vec);
    vec = generate_sorted_vector(1000000);
    seqsort(vec);
    check_sorted(vec);
    vec = generate_reversed_vector(1000000);
    seqsort(vec);
    check_sorted(vec);
}

TEST(Tests, ParallelSorting) {
    std::vector<int> vec = generate_random_vector(1000000);
    parsort(vec);
    check_sorted(vec);
    vec = generate_sorted_vector(1000000);
    parsort(vec);
    check_sorted(vec);
    vec = generate_reversed_vector(1000000);
    parsort(vec);
    check_sorted(vec);
}
