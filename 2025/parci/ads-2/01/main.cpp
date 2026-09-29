/*
 *  Mathe Ruben-Jonathan
 *  512/1
 *  mrim2553
 *
 *  lab fel 3 / 1
 *
 */

#include <iostream>
#include "LList.h"

using namespace std;

void getN(int &n)
{
    cin >> n;
}

void read(LList* v, int n)
{
    int x = 0;
    while(n!=0)
    {
        cin >> x;
        Insert(v,x);
        n--;
    }
}

int main()
{
    // INIT
    LList* v = Create();
    int n = 0;

    // IN
    getN(n);
    read(v,n);

    DelSub50(v);

    // OUT
    Print(v);

    // CLEANUP
    Destroy(v);
    return 0;
}