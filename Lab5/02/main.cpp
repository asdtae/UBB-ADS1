/*
 *  Mathe Ruben-Jonathan
 *  512
 *  Lab5/02
 *
 *  Kijelentes:
 *  Adot ket csoport felev vegi atlagainak listaja (novekvo sorrendben).
 *  Allıtsunk elo ezekbol egyetlen listat, mely szinten novekvo sorrendben van!
 */

#include <iostream>
#include "LList.h"

using namespace std;

void getN(int &n)
{
    cin >> n;
}

void read(LList* v, int &n)
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

    cout << "Enter number of elements: ";

    return 0;
}

/*
 *  Res0: 4.1 4.2 5.9 5.9 6.1 6.23 7.7 7.8 8.2 8.7 9.53 9.61
 *  Ans0: 4.1 4.2 5.9 5.9 6.1 6.23 7.7 7.8 8.2 8.7 9.53 9.61
 *
 *  Res1: 4.1 5.9 7.8 8.7 9.53 4.2 5.9 6.1 6.23 7.7 8.2 9.61
 *  Ans1: 4.1 4.2 5.9 5.9 6.1 6.23 7.7 7.8 8.2 8.7 9.53 9.61
 *
 *  Res2: 4.1 4.2 5.9 5.9 6.1 6.23 7.7 7.8 8.2 8.7 9.53 9.61
 *  Ans2: 4.1 4.2 5.9 5.9 6.1 6.23 7.7 7.8 8.2 8.7 9.53 9.61
 *
 *
 */