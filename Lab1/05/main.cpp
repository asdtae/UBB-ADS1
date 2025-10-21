/*
Mathe Ruben-Jonathan
512/1
Lab1/05

Kijelentés:
 Számítsuk ki, adott n és x értékekre, a következő összeget:
     S = 1 − (x^2/2!) + (x^4/4!) − (x^6/6!) + ... +((−1)^n) * (x^2n/(2n)!)
 Megkötések:
    • 1≤n≤100
    • x64-bites valós szám (double)
    • Minden részkifejezés ábrázolható 64-bites valósként

*/

#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

long double fact(int n)
{
    long double sum=1;
    while(n>0)
    {
        sum *= n;
        n--;
    }
    return sum;
}

double calc(int n, double x)
{
    int sign;
    double sum=1;
    long double upperPart, lowerPart;
    double preSum;

    for(int i=1; i<=n; i++)
    {
        if(i%2==0) sign = 1;
        else sign = -1;

        upperPart = pow(x,2*i);
        lowerPart = fact(2*i);

        preSum = (upperPart / lowerPart);
        preSum *= sign;

        sum += preSum;
    }

    return sum;
}

int main()
{
    int n;
    double x, result;

    cin >> n >> x;

    result = calc(n,x);

    cout << fixed << setprecision(2) << result;

    return 0;
}
