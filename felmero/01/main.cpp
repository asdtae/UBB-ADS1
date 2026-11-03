/*
 *  Mathe Ruben-Jonathan
 *  mrim2578
 *  511
 *
 *  Felm1/01
 *
 *  Kijelentés:
 *      Adott egy termeszetes szam. Irjunk programot, amely kiırja a szam binaris alakjat!
 */

#include <iostream>
#include <vector>

using namespace std;

void read(unsigned int &n) {
    cin >> n;
}

void write(vector<bool> &szam) {
    bool first = true;

    for (int i = 31; i >= 0; i--) {
        if (first && szam[i]) {
            cout << '1';
            first = false;
        } else if (!first) {
            if (szam[i]) cout << '1';
            else cout << '0';
        }
    }

    cout << endl;
}

void conv(unsigned int &n, vector<bool> &szam) {
    unsigned int oszto = INT32_MAX + 1;
    int poz = 31;

    while (oszto > 0) {
        if (n >= oszto) {
            n -= oszto;
            szam[poz] = true;
        }

        oszto /= 2;
        poz--;
    }
}

int main() {
    unsigned int n = 0;
    vector<bool> szam(32,false);

    read(n);
    if (n == 0) cout << 0 << endl;
    else {
        conv(n,szam);
        write(szam);
    }

    return 0;
}
