/*
 *  Mathe Ruben-Jonathan
 *  mrim2553
 *  512/2
 *  atalakitas - potszesszio/01
 */
#include <iostream>

using namespace std;

unsigned long long int conv(unsigned long long int n, int p, int exp)
{
    if (n == 0) return 0;
    if (exp > 0)
    {
        unsigned long long int tmp = 1;

        //cout << "// ";
        for (int i = 1; i<=exp; i++)
        {
            tmp *= p;
            //cout << tmp << ' ';
        }
        //cout << endl;
        return (n%10)*tmp + conv(n/10,p,exp+1);
    }

    return 1 + conv(n/10,p,exp+1);
}

unsigned long long int getN()
{
    unsigned long long int n;
    cin >> n;
    return n;
}

void logic(const unsigned long long int& n, const int p)
{
    if (p == 10)
    {
        cout << n;
    }
    else
    {
        cout << conv(n,p,0);
    }
}

int main()
{
    unsigned long long int n = getN();
    int p = getN();
    logic(n,p);

    return 0;
}