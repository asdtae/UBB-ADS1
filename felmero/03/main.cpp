/*
 *  Mathe Ruben-Jonathan
 *  mrim2578
 *  511
 *
 *  Felm1/03
 *
 *  Kijelentés:
 *      Irjunk programot, amely ki´ırja az adott n term´eszetes sz´amot k¨ul¨onb¨oz˝o Fibonacci-sz´amok ¨osszegek´ent!
 */

#include <iostream>
#include <vector>

using namespace std;

void read(unsigned int &n) {
    cin >> n;
}

void write(const vector<unsigned int> &a) {
    const unsigned int size = a.size();

    for (unsigned int i = 0; i<size; i++) {
        cout << a[i] << ' ';
    }

    cout << endl;
}

void fact(vector<unsigned int> &a, const unsigned int &n) {
    a.push_back(1);
    a.push_back(1);
    a.push_back(2);

    for (unsigned int i = 3; i <= n && i <= 46; i++) {
        a.push_back(a[i-1]+a[i-2]);
    }
}

void build(const vector<unsigned int> &a, vector<unsigned int> &b, unsigned int &n) {
    unsigned int i = a.size() - 1;

    while (n > 0) {
        if (a[i] <= n) {
            n -= a[i];
            b.push_back(a[i]);
        }

        i--;
    }
}

int main() {
    unsigned int n = 0;
    vector<unsigned int> a, b;

    read(n);
    fact(a,n);
    build(a,b,n);
    write(b);

    return 0;
}
