/*
 *  Mathe Ruben-Jonathan
 *  mrim2578
 *  511/1
 *  prob-PT_MaganhangzokSzama_Info
 *
 *  Lab3/01
 *
 *  Kijelentés:
 *      Számoljuk meg egy adott szövegben a magánhangzók számát!
 *
 */

#include <iostream>
#include <vector>
#include <limits>
#include <cctype>

using namespace std;

static uint32_t readN() {
    uint32_t n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return n;
}

static void read(const uint32_t len, vector<char> &a) {
    cin.getline(a.data(), len + 1);
}

static void write(const uint32_t x) {
    cout << x << endl;
}

static uint32_t solve(const uint32_t len, const vector<char> &a) {
    vector<char> maganhangzok = {'a','e','i','o','u'};
    int db = 0;

    for (uint32_t i = 0; i<len; i++) {
        uint32_t j = 0;
        const char c = static_cast<char>(tolower(a[i]));

        while (j<5) {
            if (c == maganhangzok[j]) {
                db++;
                break;
            }
            j++;
        }
    }

    return db;
}

int main() {
    const uint32_t len = readN();
    vector<char> szoveg(len + 1,'\0');

    read(len,szoveg);
    write(solve(len,szoveg));

    return 0;
}