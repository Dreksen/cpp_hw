#include "tasks.h"

#include <cmath>

int NOuter::NInner::DoSomething(int lhs, int rhs) { return lhs + rhs; }

int NOuter::DoSomething(int lhs, int rhs) { return lhs - rhs; }

int NOverload::ProcessTwoArgs(int lhs, int rhs) { return lhs + rhs; }

char NOverload::ProcessTwoArgs(char lhs, char rhs) {
  return lhs > rhs ? lhs : rhs;
}

int NOverload::ProcessTwoArgs(int lhs, char rhs) { return lhs - rhs; }

unsigned int NOverflow::WithOverflow(int lhs, int rhs) { return lhs + rhs; }

uint64_t NOverflow::WithOverflow(int64_t lhs, int64_t rhs) { return lhs - rhs; }

int NLoop::SumInRange(const int lhs, const int rhs) {
  int sum = 0;
  for (int i = lhs; i < rhs; ++i)
    sum += i;
  return sum;
}

int NLoop::CountFixedBitsInRange(const int from, const int to,
                                 const int bitsCnt) {
  int r = 0, ans = 0;
  for (int i = from; i <= to; i++) {
    r = 0;
    for (int j = i; j; j >>= 1)
      r += (j & 1) % 2;
    if (bitsCnt == r) {
      ans++;
    }
  }
  return ans;
}

double NMath::ComputeMathFormula(const double a) {
  return fabs((sin(a) / 2 + cos(a)) * (sin(a) / 2 + cos(a)) + tan(a) * atan(a));
}

bool NMath::IsPositive(int arg) { return arg > 0; }

int NRecursion::CalculateFibonacci(const int arg) {
  int a = 1, b = 1, c = 1;
  for (int i = 3; i <= arg; i++) {
    c = a + b;
    a = b;
    b = c;
  }
  return c;
}
