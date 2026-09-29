/*
 *  Mathe Ruben-Jonathan
 *  512
 *
 *  Lab4/05
 *  Kijelentes:
 *  Írjunk rekurzív algoritmust, amely kiír egy n természetes
 *  számot törzstényezőkre bontva! Ne használjunk egyáltalán ismétlő struktúrát!
 *
 */

#include <iostream>
#include "intArray.h"

using namespace std;

unsigned long int getN()
{
    unsigned long int n;
    cin >> n;
    return n;
}

void sieveRec(bool* isPrime, int p, int n)
{
    if(p * p > n) return;

    if(isPrime[p])
    {
        int multiple = p * p;
        if(multiple <= n) isPrime[multiple] = false;
        int next = multiple + p;
        if(next <= n) sieveRec(isPrime, p, n);
    }

    sieveRec(isPrime, p + 1, n);
}

void collectPrimesRec(bool* isPrime, int n, intArray* primes, int idx = 0, int count = 0)
{
    if(idx > n) return;

    if(isPrime[idx])
    {
        Set(primes, count, idx);
        collectPrimesRec(isPrime, n, primes, idx + 1, count + 1);
    }
    else collectPrimesRec(isPrime, n, primes, idx + 1, count);
}

unsigned long countExponent(unsigned long n, unsigned long p, unsigned long count = 0)
{
    if(n % p != 0) return count;
    return countExponent(n / p, p, count + 1);
}

void factorizeRec(unsigned long n, intArray* primes, int idx = 0)
{
    if(n == 1 || idx >= getN(primes)) return;

    unsigned long p = Get(primes, idx);
    unsigned long count = countExponent(n, p);

    if(count > 0)
    {
        cout << p;
        if(count > 1) cout << "^" << count;
        n /= pow(p, count);

        if(n != 1) cout << "*";
    }

    factorizeRec(n, primes, idx + 1);
}

void bont(unsigned long int n, int currBase=0, int currBaseExpo=0, int i=2, bool p=false)
{
    if(n%i==0)
    {
        if(currBaseExpo == 0)
        {
            cout << i;
            currBaseExpo++;
            p = true;
        }
        else
        {
            currBaseExpo++;
        }
    }
    else
    {
        if(p)
        {
            ;
        }
    }
}

int main()
{
    unsigned long int n = getN();

    // Szita előkészítése
    bool* isPrime = new bool[n+1];
    for(int i=0; i<=n; i++) isPrime[i] = true;
    isPrime[0] = isPrime[1] = false;

    sieveRec(isPrime, 2, n);

    // Számoljuk meg, hány prím van
    int primeCount = 0;
    for(int i=2; i<=n; i++) if(isPrime[i]) primeCount++;

    // intArray létrehozása prímekhez
    intArray* primes = Create(primeCount);
    collectPrimesRec(isPrime, n, primes);

    // Faktorizáció
    factorizeRec(n, primes);
    cout << endl;

    // Felszabadítás
    Destroy(primes);
    delete[] isPrime;

    return 0;
}
