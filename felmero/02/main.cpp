/*
 *  Mathe Ruben-Jonathan
 *  mrim2578
 *  511
 *
 *  Felm1/02
 *
 *  Kijelentés:
 *      Irjunk programot, amely meghatarozza es kiırja az osszes prımszamot
 *      egy adott n termeszetes szamig (beleertve n-t, ha prım)!
 */

#include <iostream>
#include <vector>

using namespace std;

void read(int &n) {
    cin >> n;
}

void write(const vector<int> &a) {
    for (int i = 0; i<a.size(); i++) {
        cout << a[i] << ' ';
    }

    cout << endl;
}

void szita(const int &n, vector<bool> &loA) {
    loA[0] = false;
    loA[1] = false;
    if (n >= 2) loA[2] = true;
    if (n >= 3) loA[3] = true;
    if (n >= 5) loA[5] = true;

    if (n >= 7) for (int i = 7; i <= n; i += 2) {
        if ((i+1) % 6 == 0 || (i-1) % 6 == 0 && loA[i] == true) {
            // cuz 2-n kivul a tobbi paros nem primszam & 6k +- 1 alak
            // szedjuk ki a tobbszoroseit
            int j = i*2;
            while (j <= n) {
                loA[j] = false;
                j += i;
            }
        } else loA[i] = false;
    }

    // szedjuk ki 2, 3 & 5 tobbszoroseit
    int j = 6;
    while (j <= n) {
        loA[j] = false;
        j += 3;
    }

    j = 10;
    while (j <= n) {
        loA[j] = false;
        j += 5;
    }

    j = 4;
    while (j <= n) {
        loA[j] = false;
        j += 2;
    }

}

void build(const int &n, vector<bool> &loA, vector<int> &a) {
    for (int i = 2; i <= n; i++) {
        if (loA[i]) a.push_back(i);
    }
}

int main() {
    int n = 0;
    vector<bool> loA(10001,true);
    vector<int> a;

    read(n);
    szita(n,loA);
    build(n,loA,a);
    write(a);

    return 0;
}
