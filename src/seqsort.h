#pragma once

#include "common.h"

template<typename T>
void seqsort(std::vector<T>& data, size_t left, size_t right) {
    if (sort_small(data, left, right)) {
        return;
    }
    
    auto pivot = partition(data, left, right);
    seqsort(data, left, pivot);
    seqsort(data, pivot + 1, right);
}

template<typename T>
void seqsort(std::vector<T>& data) {
    seqsort(data, size_t(0), data.size());
}
