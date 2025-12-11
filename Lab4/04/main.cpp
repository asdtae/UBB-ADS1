/*
 *  Mathe Ruben-Jonathan
 *  512
 *
 *  Lab4/04
 *  Kijelentes:
 *  Állapítsuk meg (rekurzív algoritmussal), hogy az adott n természetes szám palindromszám-e vagy sem!
 *
 */

#include <iostream>
#include "intArray.h"

using namespace std;

unsigned long long int getN()
{
    unsigned long long int n;
    cin >> n;
    return n;
}

int getLen(unsigned long long n)
{
    int i=0;
    while(n>0)
    {
        i++;
        n /= 10;
    }

    return i;
}

intArray* conv2array(unsigned long long int n)
{
    int len = getLen(n);
    intArray* A = Create(len);
    int i = 0;

    while(n>0)
    {
        Set(A,i,n%10);

        i++;
        n /= 10;
    }

    return A;
}

bool pali(intArray* A, int start, int end)
{
    if(start >= end) return true;
    if(Get(A, start) != Get(A, end)) return false;
    return pali(A, start+1, end-1);
}

void out(bool p)
{
    if(p) cout << "palindrom";
    else cout << "nem palindrom";
}

int main()
{
    unsigned long long int n = getN();
    intArray* A = conv2array(n);

    out(pali(A, 0, getLen(n) - 1));

    Destroy(A);
    return 0;
}
