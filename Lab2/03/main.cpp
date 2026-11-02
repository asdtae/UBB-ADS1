/*
 *  Mathe Ruben-Jonathan
 *  mrim2578
 *  511
 *
 *  Lab2/03
 *
 *  Kijelentés:
 *      Adott egy római szám, írjuk ki arab számjegyekkel!
 *
 */

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

void read(char s[101]) {
    cin >> s;
}

void write(const int &x) {
    cout << "A megadott szam arab szamjegyekkel: " << x << endl;
}

void rom2ara(char s[101], int &x) {
    for (int i = 0; i<strlen(s); i++) {
        if (s[i] == 'M') x += 1000;
        if (s[i] == 'D') {
            if (s[i-1] == 'C') x += 400;
            else x += 500;
        }
        if (s[i] == 'C' && s[i+1] != 'D') {
            if (s[i-1] == 'X') x += 90;
            else x += 100;
        }
        if (s[i] == 'L') {
            if (s[i-1] == 'X') x += 40;
            else x += 50;
        }
        if (s[i] == 'X' && s[i+1] != 'L' && s[i+1] != 'C') {
            if (s[i-1] == 'I') x += 9;
            else x += 10;
        }
        if (s[i] == 'V') {
            if (s[i-1] == 'I') x += 4;
            else x += 5;
        }
        if (s[i] == 'I' && s[i+1] != 'X' && s[i+1] != 'V') x += 1;
    }
}

int main() {
    char s[101];
    int x = 0;
    vector<int> r(5,0);

    read(s);
    rom2ara(s,x);
    write(x);

    return 0;
}

/*
 *  I - 1
 *  V - 5
 *  X - 10
 *  L - 50
 *  C - 100
 *  D - 500
 *  M - 1000
 */
