/*
Mathe Ruben-Jonathan
512/1
Lab1/02

Kijelentés:
    Hasonlítsuk össze egy ismétlődő ciklus sebességét amely a beolvasott szám gyökéig megy el, háromféleképpen implementálva:
        • while (i*i <= n)
        • sqrt(n)-t segédváltozóba mentve a ciklus előtt
        • while (i <= sqrt(n))
    Teszteljük a három változatot n különböző értékeire 10 és 1 000 000 000 között.

*/
#include <iostream>
#include <time.h>
#include <math.h>
#include <iomanip>

using namespace std;

int main()
{
    unsigned long int n, i=0, iMax;

    cin>> n;

    //  while (i*i <= n)
    clock_t startTime1 = clock();
    while(i*i<=n)
    {
        iMax = i;
        i++;
    }
    clock_t endTime1 = clock();

    //cout << iMax << '\n';

    //  sqrt(n)-t segédváltozóba mentve a ciklus előtt
    i = 0;
    clock_t startTime2 = clock();
    double sqrt_n = sqrt(n);
    while(i<=sqrt_n)
    {
        iMax = i;
        i++;
    }
    clock_t endTime2 = clock();

    //cout << iMax << '\n';

    //  while (i <= sqrt(n))
    i = 0;
    clock_t startTime3 = clock();
    while(i<=sqrt(n))
    {
        iMax = i;
        i++;
    }
    clock_t endTime3 = clock();

    cout << iMax << '\n';

    cerr    << fixed << setprecision(32)
            << float(endTime1 - startTime1) / (float)CLOCKS_PER_SEC << '\n'
            << float(endTime2 - startTime2) / (float)CLOCKS_PER_SEC << '\n'
            << float(endTime3 - startTime3) / (float)CLOCKS_PER_SEC << '\n';

    return 0;
}