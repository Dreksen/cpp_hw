#include "task.h"

std::vector<int> HeapSort(const std::vector<int>& input) {
    std::priority_queue<int> maxHeap;
    for (int num : input) {
        maxHeap.push(num);
    }
    std::vector<int> sorted;
    while (!maxHeap.empty()) {
        sorted.push_back(maxHeap.top());
        maxHeap.pop();
    }
    for (std::size_t i = 0; i < sorted.size() / 2; i++) {
        std::swap(sorted[i], sorted[sorted.size() - i - 1]);
    }
    return sorted;
}
