#pragma once

#include <parlay/parallel.h>

#include "common.h"

template<typename T>
void parsort(std::vector<T>& data, size_t left, size_t right) {
    if (sort_small(data, left, right)) {
        return;
    }
    
    auto pivot = partition(data, left, right);
    parlay::par_do(
        [&] { parsort(data, left, pivot); },
        [&] { parsort(data, pivot + 1, right); }
    );
}

template<typename T>
void parsort(std::vector<T>& data) {
    parsort(data, size_t(0), data.size());
}
