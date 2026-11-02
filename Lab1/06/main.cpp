/*
 *  Mathe Ruben-Jonathan
 *  mrim2578
 *  511/1
 *
 *  Lab1/06
 *
 *  Kijelentés:
 *      Adott három 64-bites valós szám (double): a, b, c.
 *      Képezhetik-e ezek a számok egy háromszög oldalait?
 *      Ha igen, határozzuk meg és írjuk ki a háromszögbe írt,
 *      illetve a háromszög köré írt kör sugarát! Ha nem, írjunk ki-1-et!
 *      A hárömszögbe írt és háromszög köré írt körök sugarai és az
 *      ezek kiszámításához szükséges kifejezések minden részkifejezése ábrázolható 64-bites valósként.
 *
 *  Források:
 *
 */

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void read(double &a, double &b, double &c) {
    cin >> a >> b >> c;
}

void write(const double &x, const double &y, const bool error) {
    if (error) {
        cout << -1 << '\n';
    } else {
        cout << fixed << setprecision(3) << "\n";
        cout << x << ' ' << y << '\n';
    }
}

double getS(const double &a, const double &b, const double &c) {
    return (a + b + c)/2;
}

double getT(const double &a, const double &b, const double &c) {
    // Héron-képlet
    const double s = getS(a,b,c);
    return sqrt(s * (s-a) * (s-b) * (s-c));
}

double getINCr(const double &a, const double &b, const double &c) {
    return getT(a,b,c)/getS(a,b,c);
}

double getOUTCr(const double &a, const double &b, const double &c) {
    return (a*b*c)/(4*getT(a,b,c));
}

bool haromszogE(const double &a, const double &b, const double &c) {
    if (a+b > c && a+c > b && b+c > a) return true;
    return false;
}

int main() {
    double a, b, c;
    read(a,b,c);

    if (haromszogE(a,b,c)) {
        write(getINCr(a,b,c),getOUTCr(a,b,c),false);
    } else {
        write(0,0,true);
    }

    return 0;
}
