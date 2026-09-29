/*
Mathe Ruben-Jonathan
512/1
Lab1/01

Kijelentés:
    Hasonlítsuk össze két egész típusú változó cseréjének sebességét három különböző módszerrel:
    • segédváltozóval
    • összeadással és kivonással
    • xor cserével

*/
#include <iostream>
#include <time.h>

using namespace std;

void csereSegedValtozoval(unsigned long int &a, unsigned long int &b)
{
    unsigned long int segedValtozo;

    segedValtozo = a;
    a = b;
    b = segedValtozo;
}

void csereOsszeadasKivonas(unsigned long int &a, unsigned long int &b)
{
    if(a > b)
    {
        a -= b;
        b += a;
        a = b - a;
    }
    else
    {
        b -= a;
        a += b;
        b = a -b;
    }
}

void xorcsere(unsigned long int &a, unsigned long int &b)
{
    a = b ^ a;
    b = a ^ b;
    a = b ^ a;
}

int main()
{
    unsigned long int szam1, szam2;

    cin >> szam1 >> szam2;

    // csere seged valtozoval
    clock_t kezdoIdo1 = clock();
    for(int i=0; i<10000000; i++)
    {
        csereSegedValtozoval(szam1, szam2);
    }
    clock_t vegsoIdo1 = clock();

    // csere + -
    clock_t kezdoIdo2 = clock();
    for(int i=0; i<10000000; i++)
    {
        csereOsszeadasKivonas(szam1,szam2);
    }
    clock_t vegsoIdo2 = clock();

    // csere xor
    clock_t kezdoIdo3 = clock();
    for(int i=0; i<10000000; i++)
    {
        xorcsere(szam1,szam2);
    }
    clock_t vegsoIdo3 = clock();

    xorcsere(szam1,szam2);

    cout << szam1 << ' ' << szam2 << '\n';
    cerr << float(vegsoIdo1 - kezdoIdo1) / (float)CLOCKS_PER_SEC << '\n' << float(vegsoIdo2 - kezdoIdo2) / (float)CLOCKS_PER_SEC << '\n' << float(vegsoIdo3 - kezdoIdo3) / (float)CLOCKS_PER_SEC << '\n';

    return 0;
}
