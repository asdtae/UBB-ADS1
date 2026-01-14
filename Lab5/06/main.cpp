/*
*  Mathe Ruben-Jonathan
 *  512
 *  Lab5/06
 *
 *  Kijelentes:
 *  Egy csoporton belul sztarnak nevezzuk azt a szemelyt, akit mindenki ismer,
 *  de o nem ismer senkit. Adott egy 𝑛 × 𝑛-es matrix amely n szemely ismerettsegi
 *  viszonyat mutatja (azaz 𝑎[𝑖][𝑗] = 1, ha 𝑖 ismeri 𝑗-t). Hatarozzuk meg, hogy van-e
    sztar a csoportban, es ha igen, ırjuk ki a sorszamat.
 */

#include <iostream>
#include "Stack.h"

using namespace std;

void getN(int &n)
{
    cin >> n;
}



int main()
{
    // INIT
    Stack* s = Create();

    //


    // CLEANUP
    Destroy(s);
}