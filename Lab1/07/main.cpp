/*
 *  Mathe Ruben-Jonathan
 *  mrim2578
 *  511/1
 *
 *  Lab1/07
 *
 *  Kijelentés:
 *      Írjunk algoritmust az ax2+bx+c = 0 valós együtthatójú egyenlet megoldására!
 *      Az együtthatók 128-bites valós számok (long double).
 *      Garantált, hogy a b2−4ac kifejezés és annak minden részkifejezése is ábrázolható 128-bites valós számként.
 *
 *  Források:
 *
 */

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void read(long double &a, long double &b, long double &c) {
    cin >> a >> b >> c;
}

void write(long double &x, long double &y, const int error) {
    if (x > y) {
        const long double mem = x;
        x = y;
        y = mem;
    }

    if (error == 0) {
        cout << fixed << setprecision(1) << "\n";
        cout << x << ' ' << y << '\n';
    } else if (error == 1) {
        cerr << "Nem letezik ket kulombozo valos gyok" << '\n';
    } else if (error == 2) {
        cerr << "Nem leteznek valos gyokei" << '\n';
    } else if (error == 3) {
        cerr << "'a' nulla" << '\n';
    }
}

long double getDelta(const long double &a, const long double &b, const long double &c) {
    return b*b - (4*a*c);
}

int getXY(const long double &a, const long double &b, const long double &c, long double &x, long double &y) {
    const long double delta = getDelta(a,b,c);

    if (delta == 0) return 1;
    if (delta < 0) return 2;
    if (a == 0) return 3;

    x = (-b + sqrt(delta))/(2*a);
    y = (-b - sqrt(delta))/(2*a);

    return 0;
}

int main() {
    long double a, b, c, x = 0, y = 0;
    read(a,b,c);
    const int error = getXY(a,b,c,x,y);
    write(x,y,error);

    return 0;
}
