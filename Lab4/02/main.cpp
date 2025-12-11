/*
 *  Mathe Ruben-Jonathan
 *  512
 *
 *  Lab4/02
 *  Kijelentes:
 *  Rendezzünk egy n elemű tömböt számjegyes rendezéssel!
 *
 */

#include <iostream>
#include "intArray.h"

using namespace std;

int getN()
{
    int n;
    cin >> n;
    return n;
}

void getNumbs(intArray* A, int n)
{
    for(int i=0; i<n; i++)
    {
        unsigned long long int tmp;
        cin >> tmp;
        Set(A,i,tmp);
    }
}

void countSort(intArray* A, int n, unsigned long long int exp)
{
    intArray* db = Create(10);
    intArray* B = Create(n);

    for(int i=0; i<n; i++)
    {
        unsigned long long int loc = Get(A, i);
        loc = (loc/exp)%10;
        Set(db,loc,Get(db,loc)+1);
    }
    for(int i=1; i<10; i++)
    {
        Set(db,i,Get(db,i)+Get(db,i-1));
    }
    for(int i=n-1; i>=0; i--)
    {
        unsigned long long int loc = Get(A, i);
        loc = (loc/exp)%10;
        unsigned long long int j = Get(db,loc);

        Set(B,j-1,Get(A, i));
        Set(db,loc,j-1);
    }

    for(int i=0; i<n; i++)
    {
        Set(A,i,Get(B,i));
    }

    Destroy(db);
    Destroy(B);
}

void radixSort(intArray* A, int n)
{
    unsigned long long maxi = Get(A, 0);
    for(int i=1; i<n; i++)
    {
        if(Get(A,i) > maxi)
        {
            maxi = Get(A, i);
        }
    }

    unsigned long long int exp = 1;
    while(maxi / exp > 0)
    {
        countSort(A,n,exp);

        if (exp > maxi / 10) break;
        exp *= 10;
    }
}

int main()
{
    // INIT
    int n = getN();
    intArray* A = Create(n);

    // READ
    getNumbs(A,n);

    // SORT
    radixSort(A,n);

    // PRINT + CLEANUP
    Print(A);
    Destroy(A);

    return 0;
}
