/*
 *  Mathe Ruben-Jonathan
 *  512
 *  Lab5/04
 *
 *  Kijelentes:
 *  Adott egy 𝑛 elemu, egesz szamokbol allo rendezett halmaz
 *  es egy 𝑥 egesz szam. Keressuk meg azokat a szamparokat, melyek osszege 𝑥.
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
        Insert(v,tmp);
        n--;
    }
}

int main()
{
    // INIT
    int len = 0;
    int x = 0;
    DLList* v = Create();

    // IN
    getN(len);
    getN(x);
    read(v,len);

    // OUT
    Multiple(v,len,x);

    // CLEANUP
    Destroy(v);
}