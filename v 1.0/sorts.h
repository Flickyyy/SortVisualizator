#pragma once
#include <vector>
#include <functional>

//classic bubble sort in N^2/2
template<class _Ty>
void bubble_sort(std::vector<_Ty>& vec, std::function<bool(_Ty, _Ty)> comp) {
    for (size_t i = vec.size(); i > 1; i--) {
        for (size_t j = 0; j + 1 < i; j++) {
            if (!comp(vec[j], vec[j + 1])) {
                std::swap(vec[j], vec[j + 1]);
            }
        }
    }
}

//straight forward implementation
template<class _Ty>
void selection_sort(std::vector<_Ty>& vec, std::function<bool(_Ty, _Ty)> comp) {
    for (size_t i = 0; i < vec.size(); i++) {
        size_t besti = i;
        for (size_t j = i + 1; j < vec.size(); j++) {
            if (!comp(vec[besti], vec[j])) besti = j;
        }
        std::swap(vec[i], vec[besti]);
    }
}