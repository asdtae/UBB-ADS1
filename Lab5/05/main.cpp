/*
*  Mathe Ruben-Jonathan
 *  512
 *  Lab5/05
 *
 *  Kijelentes:
 *  Adott egy kifejezes fordıtott lengyel formaban.
 *  Irjatok alkalmazast, amely kiertekeli a kifejezest.
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