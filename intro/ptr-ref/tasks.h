#pragma once
#include "vector"
#define ll long long
namespace NPointers {
void Increment(int *a);

int Multiply(int a, int b, bool *rt);

int ScalarProduct(const int *a, const int *b, int n);

int SizeOfMaximumSquareOfCrosses(const char *matrix, int n, int m);

long long *MultiplyToLongLong(int a, int b);
/* To implement:
Increment
Multiply
ScalarProduct
SizeOfMaximumSquareOfCrosses
MultiplyToLongLong
*/
} // namespace NPointers

namespace NReferences {
void MultiplyInplace(int& a, const int b);

int CompareArraysByAverage(const int *arr, int n, const int *arr2);
/* To implement:
MultiplyInplace
CompareArraysByAverage
*/
} // namespace NReferences
