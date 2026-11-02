/*
 *  Mathe Ruben-Jonathan
 *  mrim2578
 *  511/1
 *
 *  Lab1/04
 *
 *  Kijelentés:
 *      Számítsuk ki egy háromszög területét, ha ismerjük oldalainak a hosszát!
 *      Az oldalak hosszai 64-bites valós számok (double).
 *      A háromszög területe és a számítások során megjelenő részkifejezések mindegyike ábrázolható 64-bites valósként.
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

void write(const double &T) {
    cout << fixed << setprecision(2) << "\n";
    cout << T << '\n';
}

double getS(const double &a, const double &b, const double &c) {
    return (a + b + c)/2;
}

double getT(const double &a, const double &b, const double &c) {
    // Héron-képlet
    const double s = getS(a,b,c);
    return sqrt(s * (s-a) * (s-b) * (s-c));
}

int main() {
    double a, b, c;
    read(a,b,c);
    write(getT(a,b,c));

    return 0;
}
