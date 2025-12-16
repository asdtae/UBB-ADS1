/*
 *  Mathe Ruben-Jonathan
 *  512
 *  Lab5/01
 *
 *  Kijelentes:
 *  Adott egy n elem˝u sorozat.
 *  Irjunk programot, amely t¨orli a sorozatb´ol a 7-tel
 *  oszthat´o elemeket. A program ´ırja ki a megv´altozott sorozatot!
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
    n = DelByDiv(v,n,7);

    // WRITE
    write(v,n);

    // CLEANUP
    Destroy(v);
    return 0;
}
