#include <iostream>
#include "charArray.h"

using namespace std;

struct charArray
{
    int n;
    char *elements;
};

charArray* Create_C(int n)
{
    charArray* A = new charArray;
    A -> n = n;
    A -> elements = new char[n];

    for(int i=0; i<n; i++) A -> elements[i] = '\0';

    return A;
}

void Destroy_C(charArray* A)
{
    delete[] A -> elements;
    delete A;
}

char GetElement_C(charArray* A, int i)
{
    if((i < 0) || (i >= A -> n)) return ERROR;

    return A -> elements[i];
}

void SetElement_C(charArray* A, int i, char x)
{
    if((i < 0) || (i >= A -> n)) return;

    A -> elements[i] = x;
}

void Inp_C(charArray* A)
{
    int i = 0;
    char tmp = '0';

    do
    {
        tmp = cin.get();
        //cout << tmp << ' ' << i << '\n';

        if(tmp != '\n')
        {
            SetElement_C(A,i,tmp);
        }

        i++;
    }
    while(tmp != '\n' && i<A->n);
}

void Print_C(charArray* A)
{
    for(int i=0; i<A -> n; i++)
    {
        cout << GetElement_C(A,i);
    }
}