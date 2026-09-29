/*
Mathe Ruben-Jonathan
512/1
Lab1/04

Kijelentés:
 Számítsuk ki egy háromszög területét, ha ismerjük oldalainak a hosszát!
 Az oldalak hosszai 64-bites valós számok (double).
 A háromszög területe és a számítások során megjelenő részkifejezések mindegyike ábrázolható 64-bites valósként.

*/

#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

double getArea(double a, double b, double c)
{
    double area = 0, s;

    s = a + b + c;

    s /= 2;

    area = (s - a) * (s - b) * (s - c);

    area *= s;

    if(area > 0) area = sqrt(area);
    else area = 0;

    return area;
}

int main()
{
    double a, b, c, area;

    cin >> a >> b >> c;

    area = getArea(a,b,c);

    cout << fixed << setprecision(2) << area;

    return 0;
}