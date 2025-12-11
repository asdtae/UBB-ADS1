/*
 *  Mathe Ruben-Jonathan
 *  512
 *
 *  Lab4/01
 *  Kijelentes:
 *  Rendezzünk egy n elemű tömböt beszúró rendezéssel!
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
        long long int tmp;
        cin >> tmp;
        Set(A,i,tmp);
    }
}

void insertionSort(intArray* A, int n)
{
    for(int i=1; i<n; i++)
    {
        long long int tmp = Get(A,i);
        int j = i - 1;

        while((j>=0) && (Get(A,j)>tmp))
        {
            Set(A,j+1,Get(A,j));
            j--;
        }

        Set(A,j+1,tmp);

        //cout << "per pill: ";
        //Print(A);
        //cout << endl;
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
    insertionSort(A,n);

    // PRINT + CLEANUP
    Print(A);
    Destroy(A);

    return 0;
}
