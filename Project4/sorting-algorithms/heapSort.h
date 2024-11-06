#ifndef SORTING_HEAPSORT_H
#define SORTING_HEAPSORT_H

#include <vector>
using std::vector;

inline int leftChild(const int& i) {
    return 2 * i + 1;
}

template <typename Comparable>
void percolateDown(vector<Comparable>& items, int i, unsigned long n, unsigned long& reads, unsigned long& allocations) {
    Comparable tmp = items[i];
    reads++; // Read the item for tmp

    int child;
    while (leftChild(i) < n) {
        child = leftChild(i);
        reads += 2; // Read child values for comparison
        if (child != n - 1 && items[child] < items[child + 1]) {
            child++;
        }
        if (tmp < items[child]) {
            items[i] = items[child];
            i = child;
        } else {
            break;
        }
    }
    items[i] = tmp;
    allocations++; // Account for swap
}

template <typename Comparable>
vector<Comparable> heapSort(vector<Comparable> items, unsigned long& reads, unsigned long& allocations) {
    reads = allocations = 0;

    int n = items.size();
    for (int i = n / 2 - 1; i >= 0; --i) {
        percolateDown(items, i, n, reads, allocations);
    }

    for (int j = n - 1; j > 0; --j) {
        std::swap(items[0], items[j]);
        allocations++;
        percolateDown(items, 0, j, reads, allocations);
    }

    return items;
}

#endif // SORTING_HEAPSORT_H
