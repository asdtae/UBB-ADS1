/*
 *  Mathe Ruben-Jonathan
 *  512/1
 *
 *  LAB 3/02
 *  Kijelentes:
 *  Adott egy csoport év végi vizsgajegyeinek listája.
 *  Töröljük ki az 5-ösnél kisebb jegyeket a listából.
 *  A módósítást a beolvasott tömbben kell elvégezni, nem elég csak kiíratni az eredményt.
 *
 */

#include <iostream>
#include <stdio.h>
//#include "charArray.h"
#include "intArray.h"

#define DEBUG false

using namespace std;

void in_n(int &n)
{
    cin >> n;
}

int main()
{
    // INIT A
    int n;
    in_n(n);
    intArray* A = Create_I(n);
    Inp_I(A);


    Print_I(A);
    Destroy_I(A);
    return 0;
}
