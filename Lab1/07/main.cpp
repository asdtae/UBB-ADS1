/*
Mathe Ruben-Jonathan
512/1
Lab1/07

Kijelentés:
 Írjunk algoritmust az ax2+bx+c = 0 valós együtthatójú egyenlet megoldására!
 Az együtthatók 128-bites valós számok (long double).
 Garantált, hogy a b^2−4ac kifejezés és annak minden részkifejezése is ábrázolható 128-bites valós számként.

*/

#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int main()
{
    long double a=0, b=0, c=0, delta;
    long double x1, x2;

    cin >> a >> b >> c;

    if(a!=0)
    {
        delta = b * b - 4 * a * c;
        if(delta > 0)
        {
            delta = sqrt(delta);

            x1 = (-b + delta) / (2*a);
            x2 = (-b - delta) / (2*a);

            cout << fixed << setprecision(1);

            if(x1<x2) cout << x1 << ' ' << x2;
            else cout << x2 << ' ' << x1;
        }
        else if(delta == 0)
        {
            x1 = (-b ) / (2*a);

            cout << fixed << setprecision(1);

            cout << x1 << ' ' << x1;
        }
        else
        {
            cerr << "Nem letezik x1, x2; hiszen delta < 0";
        }
    }
    else
    {
        cerr << "nem masodfoku";
    }

    return 0;
}
