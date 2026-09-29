#include <iostream>
#include "intArray.h"

using namespace std;

struct intArray
{
    int n;
    int *elements;
};

intArray* Create_I(int n)
{
    intArray* A = new intArray;
    A -> n = n;
    A -> elements = new int[n];

    for(int i=0; i<n; i++) A -> elements[i] = 0;

    return A;
}

void Destroy_I(intArray* A)
{
    delete[] A -> elements;
    delete A;
}

int GetElement_I(intArray* A, int i)
{
    if((i < 0) || (i >= A -> n)) return ERROR;

    return A -> elements[i];
}

void SetElement_I(intArray* A, int i, int x)
{
    if((i < 0) || (i >= A -> n)) return;

    A -> elements[i] = x;
}

void Inp_I(intArray* A)
{
    int i = 0;
    int tmp = 0;

    do
    {
        cin >> tmp;
        cout << tmp << ' ' << i << '\n';

        if(tmp != '\n' && tmp != ' ')
        {
            SetElement_I(A,i,tmp);
            i++;
        }
    }
    while(tmp != '\n' && i<A->n);
}

void Print_I(intArray* A)
{
    for(int i=0; i<A -> n; i++)
    {
        cout << GetElement_I(A,i) << ' ';
    }
}