#include "tasks.h"
#include "vector"
#include <climits>
#include <algorithm>
#define ll long long
namespace NPointers {
void Increment(int *a) { (*a)++; }

int Multiply(int a, int b, bool *rt) {
  *rt = false;
  if (a > INT_MAX / b) {
    *rt = true;
  }

  return a * b;
}

int ScalarProduct(const int *a, const int *b, int n) {
  int r = 0;
  for (int i = 0; i < n; i++) {
    r += a[i] * b[i];
  }
  return r;
}

int SizeOfMaximumSquareOfCrosses(const char *matrix, int n, int m) {
  std::vector<std::vector<int>> dp(n, std::vector<int>(m, 0));
  int maxSize = 0;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (matrix[i * m + j] == '+') {
        if (i == 0 || j == 0) {
          dp[i][j] = 1;
        } else {
          dp[i][j] =
              std::min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
        }
        maxSize = std::max(maxSize, dp[i][j]);
      }
    }
  }
  return maxSize;
}

long long *MultiplyToLongLong(int a, int b) {
  ll a1 = a, b1 = b;
  ll *c = new ll;
  *c = a1 * b1;
  return c;
}
/* To implement:
Increment
Multiply
ScalarProduct
SizeOfMaximumSquareOfCrosses
MultiplyToLongLong
*/
} // namespace NPointers

namespace NReferences {
void MultiplyInplace(int& a, const int b) { a *= b; }

int CompareArraysByAverage(const int *arr, int n, const int * arr2)
{
  int m = 5;
  ll sum1 = 0, sum2 = 0;
  for (int i = 0; i < n; i++) {
    sum1 += arr[i];
  }
  for (int i = 0; i < m; i++) {
    sum2 += arr2[i];
  }
  if (sum1 * m > sum2 * n) {
    return 1;
  }
  if (sum1 * m < sum2 * n) {
    return -1;
  }
  return 0;
}
/* To implement:
MultiplyInplace
CompareArraysByAverage
*/
} // namespace NReferences
