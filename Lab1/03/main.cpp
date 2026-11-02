/*
 *  Mathe Ruben-Jonathan
 *  mrim2578
 *  511/1
 *  prob-Asz2_DiszjunktHalmazok
 *
 *  Lab1/03
 *
 *  Kijelentés:
 *      Olvassunk be a billentyűzetről három 64-bites előjeles egész számot.
 *      Írjuk ki őket növekvő sorrendben! Ne rendezzük a számokat, csak írjuk ki a kért sorrendben.
 *      Egymás utáni elágazások helyett, egymásba ágyazottakat alkalmazzunk.
 *
 *  Források:
 *
 */

#include <iostream>

using namespace std;

void read(long long &a, long long &b, long long &c) {
    cin >> a >> b >> c;
}

void write(const long long &n) {
    cout << n << '\n';
}

int main() {
    long long a, b, c;
    read(a,b,c);

    if (a > b) {
        if (a > c) {
            if (b > c) {
                cout << c << ' ' << b << ' ' << a << '\n';
            } else {
                cout << b << ' ' << c << ' ' << a << '\n';
            }
        } else {
                cout << b << ' ' << a << ' ' << c << '\n';
        }
    } else {
        if (a > c) {
                cout << c << ' ' << a << ' ' << b << '\n';
        } else {
            if (b > c) {
                cout << a << ' ' << c << ' ' << b << '\n';
            } else {
                cout << a << ' ' << b << ' ' << c << '\n';
            }
        }
    }

    return 0;
}
