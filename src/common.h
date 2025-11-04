#pragma once

#include <vector>
#include <cstddef>

template<typename T>
inline size_t median_of_three(std::vector<T>& data, size_t left, size_t mid, size_t right) {
    if ((data[left] <= data[mid] && data[left] >= data[right]) ||
        (data[left] >= data[mid] && data[left] <= data[right])) {
        return left;
    }
    if ((data[mid] <= data[left] && data[mid] >= data[right]) ||
        (data[mid] >= data[left] && data[mid] <= data[right])) {
        return mid;
    }
    return right;
}

template<typename T>
inline bool sort_small(std::vector<T>& data, size_t left, size_t right) {
    auto size = right - left;
    if (size <= 1) {
        return true;
    } else if (size == 2) {
        if (data[left] > data[left + 1]) {
            std::swap(data[left], data[left + 1]);
        }
        return true;
    }
    else if (size == 3) {
        if (data[left] > data[left + 1]) {
            std::swap(data[left], data[left + 1]);
        }
        if (data[left + 1] > data[left + 2]) {
            std::swap(data[left + 1], data[left + 2]);
        }
        if (data[left] > data[left + 1]) {
            std::swap(data[left], data[left + 1]);
        }
        return true;
    }
    return false;
}

template<typename T>
size_t partition(std::vector<T>& data, size_t left, size_t right) {
    auto mid = left + (right - left) / 2;
    auto pivotIndex = median_of_three(data, left, mid, right - 1);
    std::swap(data[pivotIndex], data[right - 1]);
    
    auto pivot = data[right - 1];
    auto i = left;
    for (size_t j = left; j < right - 1; j++) {
        if (data[j] < pivot) {
            std::swap(data[i], data[j]);
            i++;
        }
    }
    std::swap(data[i], data[right - 1]);
    return i;
}
