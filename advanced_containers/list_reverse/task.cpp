#include "task.h"

void ReverseList(std::list<int>& l) {
    auto itl = l.begin(), itr = l.end();
    itr--;
    while (itl != itr) {
        std::swap(*itl, *itr);
        itl++;
        itr--;
    }
}
