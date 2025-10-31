/*
 * Mathe Ruben-Jonaathan
 * 512/1
 */

#include <iostream>

using namespace std;

int i=0;

void base10tobase2(unsigned long n, int result[33])
{
    while(n>0)
    {
        result[i] = n % 2;
        //cout << result[i];
        n /= 2;
        i++;
    }
    //cout << '\n';
}

int main()
{
    unsigned long numb;
    int result[33]={0};

    cin >> numb;

    if(numb == 0) cout << 0;
    else
    {
        base10tobase2(numb, result);
        i--;

        while(i>=0)
        {
            cout<<result[i];
            i--;
        }
    }

    return 0;
}