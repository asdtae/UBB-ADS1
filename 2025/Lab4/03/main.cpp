/*
 *  Mathe Ruben-Jonathan
 *  512
 *
 *  Lab4/03
 *  Kijelentes:
 *  Írjunk rekurzív algoritmust, amely kiszámítja egy n-edfokú polinom értékét egy adott valós x pontban!
 *  Ne használjunk ismétlő struktúrát a beolvasáson kívül!
 *
 */

#include <iostream>
#include "intArray.h"

using namespace std;

double getDN()
{
    double n;
    cin >> n;
    return n;
}

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

double polyRec(intArray* A, long long i, double x) {
    if (i == 0)
    {
        return (double)Get(A, 0);
    }
    else
    {
        double prev = polyRec(A, i - 1, x);
        return prev * x + (double)Get(A, i);
    }
}

void out(double &n)
{
    cout << (long long)(n) << endl;
}

int main()
{
    // INIT
    int n = getN();
    int m = n + 1;

    intArray* A = Create(m);

    // READ
    getNumbs(A,m);
    double x = getDN();

    double res = polyRec(A, n, x);

    // CLEANUP
    out(res);
    Destroy(A);

    return 0;
}
