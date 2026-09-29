/*
*  Mathe Ruben-Jonathan
 *  512/2
 *  mrim2553
 *  szesszio_csut_02
 *
 */
#include <iostream>
#include "fa.h"

using namespace std;

void readN(int *n)
{
    cin >> *n;
}

void readData(int n, tree* t)
{
    int x = 0;

    for (int i=0; i<n; i++)
    {
        cin >> x;
        Insert(t,x);
    }
}

int main()
{
    int n;
    readN(&n);

    tree *t = Create();
    readData(n,t);

    ReadPost(t);

    Destroy(t);
    return 0;
}