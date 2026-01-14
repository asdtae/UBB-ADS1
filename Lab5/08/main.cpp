/*
*  Mathe Ruben-Jonathan
 *  512
 *  Lab5/08
 *
 *  Kijelentes:
 *  Adott 𝑛 folyamat. Minden folyamatnak ismerjuk az azonosıtojat (PID) es a
 *  vegrehajtashoz szukseges idoegyseget.
 *  Irjunk alkalmazast, amely a folyamatok utemezeset szimulalja, a kovetkezo
 *  modon
 */

#include <iostream>
#include "Queue.h"

using namespace std;

void getN(int &n)
{
    cin >> n;
}

int main()
{
    // INIT
    int n;
    getN(n);

    Queue* q = Create();

    for(int i = 0; i < n; i++)
    {
        Process p;
        cin >> p.pid >> p.time;
        Enqueue(q, p);
    }

    long long int currTime = 0;
    long long int totalTime = 0;

    while (!IsEmpty(q))
    {
        Process p = Dequeue(q);
        totalTime += currTime;
        currTime += p.time;
    }

    float res = (float)(totalTime) / n;

    cout << fixed << setprecision(2) << res << endl;

    // CLEANUP
    Destroy(q);
}