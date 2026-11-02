/*
 *  Mathe Ruben-Jonathan
 *  mrim2578
 *  511/1
 *
 *  Lab2/01
 *
 *  Kijelentés:
 *      Bontsunk fel egy adott számot 2 hatványainak összegére!
 *
 */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void read(unsigned long long int &n) {
    cin >> n;
}

void calc(unsigned long long int &n, vector<bool> &o) {
    unsigned long long int x = pow(2,63);
    int xPow = 63;

    while (n > 0) {
        if (n >= x) {
            n -= x;
            x /= 2;

            o[xPow] = true;
            xPow--;
        } else {
            x /= 2;
            xPow--;
        }
    }
}

void write(vector<bool> &o) {
    bool p = false;

    for (int i = 63; i >= 0; i--) {
        if (o[i] && !p) {
            cout << "2^" << i;
            p = true;
        } else if (o[i] && p) cout << '+' << "2^" << i;
    }

    cout << endl;
}

int main() {
    unsigned long long int n = 0;
    vector<bool> o(64,false);

    read(n);
    calc(n,o);
    write(o);

    return 0;
}
