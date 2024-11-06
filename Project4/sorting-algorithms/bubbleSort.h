#ifndef SORTING_BUBBLESORT_H
#define SORTING_BUBBLESORT_H

#include <vector>

template<typename Comparable>
std::vector<Comparable> bubbleSort(std::vector<Comparable> vec, unsigned long& reads, unsigned long& allocations) {
    // Initialize reads and allocations
    reads = allocations = 0;

    // Record the initial allocation for the input vector
    allocations += sizeof(Comparable) * vec.size();

    bool swapped; // Flag to track if a swap occurred
    int n = vec.size();

    // Outer loop for passes through the vector
    do {
        swapped = false; // Reset swapped flag for this pass
        for (int i = 0; i < n - 1; ++i) {
            reads += 2; // Read two elements for comparison
            if (vec[i] > vec[i + 1]) {
                // Swap elements
                std::swap(vec[i], vec[i + 1]);
                swapped = true; // Set the flag to true as we swapped
                reads += 3; // Read/write three elements during the swap
            }
        }
        --n; // Reduce the size of the unsorted portion
    } while (swapped); // Continue until no swaps occur

    return vec; // Return the sorted vector
}

#endif // SORTING_BUBBLESORT_H
