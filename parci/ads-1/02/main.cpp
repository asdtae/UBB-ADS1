/*
 * Mathe Ruben-Jonaathan
 * 512/1
 */

#include <iostream>

using namespace std;

bool sameLen(unsigned long long n1, unsigned long long n2)
{
    while(n1>0 && n2>0)
    {
        n1 /= 10;
        n2 /= 10;
    }

    if(n1 == n2) return true;
    return false;
}

bool anagramma(unsigned long long n1, unsigned long long n2)
{
    int fq1[10] = {0};
    int fq2[10] = {0};

    while(n1>0)
    {
        fq1[n1 % 10] ++;
        n1 /= 10;
    }

    while(n2>0)
    {
        fq2[n2 % 10] ++;
        n2 /= 10;
    }

    for(int i=0; i<10; i++)
    {
        if(fq1[i] != fq2[i]) return false;
    }

    return true;
}

int main()
{
    unsigned long long numb1;
    unsigned long long numb2;

    cin >> numb1 >> numb2;

    if(sameLen(numb1,numb2))
    {
        if(anagramma(numb1,numb2))
            cout << "Igen";
        else cout << "Nem";
    }
    else cout << "Nem";

    return 0;
}