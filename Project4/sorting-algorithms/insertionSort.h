#ifndef SORTING_INSERTIONSORT_H
#define SORTING_INSERTIONSORT_H

#include <vector>
using std::vector;

template<typename Comparable>
vector<Comparable> insertionSort(vector<Comparable> vec, unsigned long& reads, unsigned long& allocations) {
    reads = allocations = 0;

    for (int unsortedStartIndex = 1; unsortedStartIndex < vec.size(); ++unsortedStartIndex) {
        Comparable toBeInserted = vec[unsortedStartIndex];
        reads++; // Read for toBeInserted

        int insertIndex = unsortedStartIndex - 1;
        while (insertIndex >= 0 && vec[insertIndex] > toBeInserted) {
            vec[insertIndex + 1] = vec[insertIndex];
            reads++; // Read for comparison
            allocations++; // Allocation for shifting elements
            --insertIndex;
        }
        vec[insertIndex + 1] = toBeInserted;
        allocations++; // Allocation for final placement
    }

    return vec;
}

#endif // SORTING_INSERTIONSORT_H
