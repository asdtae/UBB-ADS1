/*
 *  Mathe Ruben-Jonathan
 *  mrim2578
 *  511/1
 *
 *  Lab1/08
 *
 *  Kijelentés:
 *      Számítsuk ki hány szökőév volt/lesz két évszám között,
 *      mindkét évszámot beleszámítva! Minden évet szökőévnek tekintünk,
 *      ha osztható 4-gyel és nem osztható 100-zal, vagy osztható 400-zal.
 *      Például 1964 szökőév, 1900 nem szökőév, 2000 szökőév.
 *
 *  Források:
 *
 */

#include <iostream>

using namespace std;

void read(unsigned long long &x, unsigned long long &y) {
    cin >> x >> y;
}

void write(const unsigned long long &res) {
    cout << res << endl;
}

unsigned long long calc(unsigned long long &x, unsigned long long &y) {
    if (x == 0) return y/4 - y/100 + y/400 + 1;

    x--;
    x = x/4 - x/100 + x/400;
    y = y/4 - y/100 + y/400;

    // cout << x << ' ' << y << '\n';

    if (y != 0) return y - x;
    return x;
}

int main() {
    unsigned long long x, y;
    read(x,y);
    write(calc(x,y));

    return 0;
}
