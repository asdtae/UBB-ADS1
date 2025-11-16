#include "IntArray.h"
#include <iostream>

using namespace std;

struct IntArray
{
    int n;
    int* elements;
};

IntArray* Create(int n)
{
    IntArray* A = new IntArray;
    A -> n = n;
    A -> elements = new int[n];

    for(int i = 0; i < n; i++) A -> elements[i] = 0;

    return A;
}

void Destroy(IntArray* A)
{
    delete[] A -> elements;
    delete A;
}

int GetElement(IntArray* A, int i)
{
    if((i >= A -> n) || (i < 0)) return ERROR;

    return A -> elements[i];
}

void SetElement(IntArray* A, int i, int value)
{
    if((i >= A -> n) || (i < 0)) return;

    A -> elements[i] = value;
}

void PushBack(IntArray* A, int value)
{
    ;
}

void Print(IntArray* A)
{
    for(int i = 0; i < A -> n; i++)
    {
        cout << A -> elements[i] << ' ';
    }

    cout << endl;
}