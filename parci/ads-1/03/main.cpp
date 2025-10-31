/*
 * Mathe Ruben-Jonaathan
 * 512/1
 */

#include <iostream>

using namespace std;

int i=0;
unsigned long f[100000] = {0};

int fibo(unsigned long n1, unsigned long n2, unsigned long numb)
{
    unsigned long mem;

    if(n2<=numb)
    {
        mem = n2;
        n2 = n1 + n2;
        n1 = mem;
        //cout << n1 << ' ';
        f[i] = n1;
        i++;
        return fibo(n1,n2,numb);
    }
    else return 0;
}

int main()
{
    unsigned long numb;
    unsigned long sum=0;

    cin >> numb;

    fibo(0,1,numb);

    i--;

    if(numb == f[i]) cout << numb;
    else
    {
        //for(int j=0; j<=i; j++) cout << f[j] << ' ';
        for(int j=i; j>=0; j--)
        {
            if(( sum + f[j] ) <= numb)
            {
                sum += f[j];
                cout << f[j] << ' ';
            }
        }
    }
}