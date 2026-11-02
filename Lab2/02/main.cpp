/*
 *  Mathe Ruben-Jonathan
 *  mrim2578
 *  511
 *
 *  Lab2/02
 *
 *  Kijelentés:
 *      Írjunk algoritmust, amely egy adott x páros számot
 *      felír két különböző prímszám összegeként (Goldbach-sejtés).
 *
 */

#include <iostream>

using namespace std;

void read(unsigned int &x) {
    cin >> x;
}

bool primee(const unsigned long long int &n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    for (unsigned long long int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }

    return true;
}

void func(const unsigned int &x) {
    unsigned long long int p = 3;

    while (p <= x) {
        const unsigned long long int q = x - p;

        if (p != q && primee(p) && primee(q)) {
            cout << x << " = " << p << " + " << q << endl;
            break;
        }

        p += 2;
    }
}

int main() {
    unsigned int x;

    read(x);
    func(x);

    return 0;
}