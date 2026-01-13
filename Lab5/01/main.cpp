/*
 *  Mathe Ruben-Jonathan
 *  512
 *  Lab5/01
 *
 *  Kijelentes:
 *  Adott egy n elemu sorozat.
 *  Irjunk programot, amely torli a sorozatbol a 7-tel
 *  oszthato elemeket. A program ırja ki a megvaltozott sorozatot!
 */

#include <iostream>
#include "LList.h"

using namespace std;

void read(LList* v, int n)
{
    long int tmp;

    while(n>0)
    {
        cin >> tmp;
        Insert(v,tmp);
        n--;
    }
}

void write(LList* v, int n)
{
    cout << n << endl;
    Print(v);
}

int main()
{
    // INIT
    LList* v = Create();
    int n;
    cin >> n;

    // READ
    read(v,n);

    // LOGIC
    DelByDiv(v,n,7);

    // WRITE
    write(v,n);

    // CLEANUP
    Destroy(v);
    return 0;
}
