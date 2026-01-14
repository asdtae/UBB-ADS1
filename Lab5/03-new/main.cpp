/*
*  Mathe Ruben-Jonathan
 *  512
 *  Lab5/03
 *
 *  Kijelentes:
 *  Adott egy 𝑛 elemu, egesz szamokbol allo tomb es
 *  egy 𝑘 egesz szam. Forgassuk el a tomb elemeit 𝑘-val (balra)!
 */

#include <iostream>
#include "DLList.h"

using namespace std;

void getN(int &n)
{
    cin >> n;
}

void read(DLList* v, int &n)
{
    type tmp = 0.0;

    while(n > 0)
    {
        cin >> tmp;
        Insert_Sorted(v,tmp);
        n--;
    }
}

int main()
{
    // INIT
    int len = 0;
    int k = 0;
    DLList* v = Create();

    // IN
    getN(len);
    getN(k);
    read(v,len);

    // SHIFT
    Shift(v,k);

    // OUT
    Print(v);

    // CLEANUP
    Destroy(v);
}