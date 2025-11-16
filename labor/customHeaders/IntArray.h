#pragma once

#include <climits>
#define ERROR INT_MIN

struct IntArray;

IntArray* Create(int);
void Destroy(IntArray*);

int GetElement(IntArray*, int);
void SetElement(IntArray*, int, int);
void PushBack(IntArray*, int);

void Print(IntArray*);