#include <iostream>
#include "intArray.h"

using namespace std;

struct intArray
{
    int n;
    long long int *elements;
};

intArray* Create(int n)
{
    intArray* A = new intArray;
    A -> n = n;
    A -> elements = new long long int[n];

    for(int i=0; i<n; i++) A -> elements[i] = 0;

    return A;
}

void Destroy(intArray* A)
{
    delete[] A -> elements;
    delete A;
}

long long int Get(intArray* A, int i)
{
    if((i < 0) || (i >= A -> n)) return ERROR;

    return A -> elements[i];
}
void Set(intArray* A, int i, long long int x)
{
    if((i < 0) || (i >= A -> n)) return;

    A -> elements[i] = x;
}

void Print(intArray* A)
{
    for(int i=0; i<A -> n; i++)
    {
        cout << Get(A,i) << ' ';
    }
}

int getN(intArray* A)
{
    return A->n;
}