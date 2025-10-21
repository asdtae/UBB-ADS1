/*
Mathe Ruben-Jonathan
512/1
Lab1/06

Kijelentés:
    Adott három 64-bites valós szám (double): a, b, c.
    Képezhetik-e ezek a számok egy háromszög oldalait?
    Ha igen, határozzuk meg és írjuk ki a háromszögbe írt, illetve a háromszög köré írt kör sugarát!
    Ha nem, írjunk ki-1-et!

    Ahárömszögbe írt és háromszög köré írt körök sugarai és az ezek kiszámításához szükséges kifejezések minden részkifejezése ábrázolható 64-bites valósként.

*/

#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

bool validTri(const double a, const double b, const double c)
{
    if(((a + b) > c) && ((a + c) > b) && ((b + c) > a)) return true;
    return false;
}

double getArea(double a, double b, double c)
{
    double area, s;

    s = a + b + c;

    s /= 2;

    area = (s - a) * (s - b) * (s - c);

    area *= s;

    if(area > 0) area = sqrt(area);
    else area = 0;

    return area;
}

double getPerimeter(const double a, const double b, const double c)
{
    double perimeter=a + b + c;
    return perimeter;
}

double getInCiR(const double A, const double P)
{
    double radius=(A/P);
    return radius;
}

double gerOutCiR(const double sumABC, const double A)
{
    double radius=(sumABC/(4*A));
    return radius;
}

int main()
{
    double a, b, c;
    double inCiR, outCiR;
    cin >> a >> b >> c;

    if(validTri(a,b,c))
    {
        inCiR   = getInCiR(getArea(a,b,c), getPerimeter(a,b,c)/2);
        outCiR  = gerOutCiR(a*b*c,getArea(a,b,c));

        cout << fixed << setprecision(3) << inCiR << ' ' << outCiR;
    }
    else cout << -1;
    return 0;
}
