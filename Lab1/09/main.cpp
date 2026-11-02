/*
 *  Mathe Ruben-Jonathan
 *  mrim2578
 *  511/1
 *
 *  Lab1/09
 *
 *  Kijelentés:
 *      Számítsuk ki, hány napot éltünk a mai nappal bezárólag!
 *      Ha valaki január 1.-én született, akkor január 2.-án élt 1 napot.
 *
 *  Források:
 *
 */

#include <iostream>
#include <vector>

using namespace std;

void read(string &s1, string &s2) {
    cin >> s1 >> s2;
}

void write(const int x) {
        cout << x << '\n';
}

void parser(const string &s1, const string &s2, vector<int> &d1, vector<int> &d2) {
    d1[0] = (s1[0] - '0') * 1000 +
            (s1[1] - '0') * 100  +
            (s1[2] - '0') * 10   +
            s1[3] - '0';

    d2[0] = (s2[0] - '0') * 1000 +
            (s2[1] - '0') * 100  +
            (s2[2] - '0') * 10   +
            s2[3] - '0';

    d1[1] = (s1[5] - '0') * 10 +
            s1[6] - '0';

    d2[1] = (s2[5] - '0') * 10 +
            s2[6] - '0';

    d1[2] = (s1[8] - '0') * 10 +
            s1[9] - '0';

    d2[2] = (s2[8] - '0') * 10 +
            s2[9] - '0';
}

int szoko(int x, int y) {
        if (x == 0) return y/4 - y/100 + y/400 + 1;

        x--;
        x = x/4 - x/100 + x/400;
        y = y/4 - y/100 + y/400;

        // cout << x << ' ' << y << '\n';

        if (y != 0) return y - x;
        return x;
}

int calc(const vector<int> &d1, const vector<int> &d2) {
    vector<int> napok(13,0);
    napok[1] = 31;
    napok[2] = 28;
    napok[3] = 31;
    napok[4] = 30;
    napok[5] = 31;
    napok[6] = 30;
    napok[7] = 31;
    napok[8] = 31;
    napok[9] = 30;
    napok[10] = 31;
    napok[11] = 30;
    napok[12] = 31;

    const int ev = d2[0] - d1[0];
    const int szokoEv = szoko(d1[0],d2[0]);
    int honap = d2[1] - d1[1];
    int nap = 0;

    if (ev == 0) {
        if (honap == 0) return d2[2] - d2[1];

        int napMaradekok = napok[d1[1]] - d1[2] + d2[2];
        for (int i = d1[1] + 1; i<d2[1]; i++) {
            nap += napok[i];
        }

        if ((d1[1] <= 2 && d1[2] <= 28 && d2[1] >= 3 && d2[2] >= 1) ||
            (d1[1] ))

        return nap + napMaradekok;
    }


}

int main() {
    string s1, s2;
    vector<int> date1(3,0), date2(3,0);

    read(s1,s2);
    parser(s1,s2,date1,date2);
    write(calc(date1,date2));

    // cout << date1[0] << ' ' << date1[1] << ' ' << date1[2] << ' ' << '\n';
    // cout << date2[0] << ' ' << date2[1] << ' ' << date2[2] << ' ' << '\n';

    return 0;
}

// 1992.01.15 2018.10.01
// 2000.01.01 2000.02.01
// 2000.01.01 2000.01.10