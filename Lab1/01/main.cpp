/*
 *  Mathe Ruben-Jonathan
 *  mrim2578
 *  511/1
 *
 *  Lab1/01
 *
 *  Kijelentés:
 *      Hasonlítsuk össze két egész típusú változó cseréjének sebességét három különböző módszerrel:
 *          • segédváltozóval
 *          • összeadással és kivonással
 *          • xor cserével
 *
 *  Források:
 *
 */

#define RUNS 99999999

#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

void read(unsigned int &a, unsigned int &b) {
    cin >> a >> b;
}

void write(unsigned int &a, unsigned int &b) {
    cout << a << ' ' << b << '\n';
}

clock_t sw_1(unsigned int &a, unsigned int &b) {
    clock_t before = clock();
    for (int i = 1; i <= RUNS; i++) {
        const unsigned int mem = a;
        a = b;
        b = mem;
    }
    clock_t after = clock() - before;

    return after;
}

clock_t sw_2(unsigned int &a, unsigned int &b) {
    clock_t before = clock();
    for (int i = 1; i <= RUNS; i++) {
        a = a + b;
        b = a - b;
        a = a - b;
    }
    clock_t after = clock() - before;

    return after;
}

clock_t sw_3(unsigned int &a, unsigned int &b) {
    clock_t before = clock();
    for (int i = 1; i <= RUNS; i++) {
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }
    clock_t after = clock() - before;

    return after;
}

int main() {
    unsigned int a, b;
    read(a,b);
    cerr << fixed << setprecision(3) << "\n";

    // segédváltozóval
    clock_t time = sw_1(a,b);
    write(a,b);
    cerr << static_cast<double>(time) / CLOCKS_PER_SEC << '\n';
    sw_1(a,b);

    // összeadással és kivonással
    time = sw_2(a,b);
    cerr << static_cast<double>(time) / CLOCKS_PER_SEC << '\n';
    sw_2(a,b);

    // xor cserével
    time = sw_3(a,b);
    cerr << static_cast<double>(time) / CLOCKS_PER_SEC << '\n';
    sw_3(a,b);

    return 0;
}
