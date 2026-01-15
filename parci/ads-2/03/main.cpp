/*
*  Mathe Ruben-Jonathan
 *  512/1
 *  mrim2553
 *
 *  lab fel 3 / 3
 *
 */

#include <iostream>
#include "Queue.h"

using namespace std;

void getN(int &n)
{
    cin >> n;
}

void getData(long int &n)
{
    cin >> n;
}

void read(Queue* v, int n, int &kdata, int k)
{
    int x = 0;
    int ogN = 0;

    while(n!=0)
    {
        cin >> x;
        if(ogN == k) kdata = x;

        Push(v,x,ogN);
        n--;
        ogN++;
    }
}

int main()
{
    // INIT
    Queue* v = Create();
    int n = 0;
    int k = 0;
    int kdata = 0;

    // IN
    getN(n);
    getN(k);
    read(v,n,kdata,k);

    // while cucc
    while(kdata!=0)
    {
        int tmp = Front(v);
    }

    // CLEANUP
    Destroy(v);
    return 0;
}