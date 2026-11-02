/*
*  Mathe Ruben-Jonathan
 *  mrim2578
 *  511/1
 *
 *  Lab1/02
 *
 *  Kijelentés:
 *      Hasonlítsuk össze egy ismétlődő ciklus sebességét amely a beolvasott szám gyökéig megy el, háromféleképpen implementálva:
 *          • while (i*i <= n)
 *          • sqrt(n)-t segédváltozóba mentve a ciklus előtt
 *          • while (i <= sqrt(n))
 *      Teszteljük a három változatot n különböző értékeire 10 és 1 000 000 000 között.
 *
 *  Források:
 *
 */

#define RUNS 99999999

#include <iostream>
#include <ctime>
#include <iomanip>
#include <cmath>

using namespace std;

void read(int &n) {
    cin >> n;
}

void write(const int &n) {
    cout << n << '\n';
}

clock_t loop_1(const int n, int &i) {
    const clock_t before = clock();

    i = 1;
    while (i*i <= n) i++;
    i--;

    const clock_t after = clock() - before;

    return after;
}

clock_t loop_2(const int n) {
    const clock_t before = clock();

    const int sqr = sqrt(n);
    int i = 1;
    while (i <= sqr) i++;
    i--;

    const clock_t after = clock() - before;

    return after;
}

clock_t loop_3(const int n) {
    const clock_t before = clock();

    int i = 1;
    while (i <= sqrt(n)) i++;
    i--;

    const clock_t after = clock() - before;

    return after;
}

int main() {
    int n;
    read(n);
    cerr << fixed << setprecision(3) << "\n";

    // segédváltozóval
    int i;
    clock_t time = loop_1(n,i);
    write(i);
    cerr << static_cast<double>(time) / CLOCKS_PER_SEC << '\n';

    // összeadással és kivonással
    time = loop_2(n);
    cerr << static_cast<double>(time) / CLOCKS_PER_SEC << '\n';

    // xor cserével
    time = loop_3(n);
    cerr << static_cast<double>(time) / CLOCKS_PER_SEC << '\n';

    return 0;
}
