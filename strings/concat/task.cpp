#include "task.h"

char *concat(const char *lhs, const char *rhs) {
    int n = 0, m = 0;
    while (lhs[n] != '\0') {
        n++;
    }
    while (rhs[m] != '\0') {
        m++;
    }
    char *res = new char[m + n + 1];
    for (int i = 0; i < n; i++) {
        res[i] = lhs[i];
    }
    for (int i = 0; i < m; i++) {
        res[i + n] = rhs[i];
    }
    res[n + m] = '\0';
    return res;
}
