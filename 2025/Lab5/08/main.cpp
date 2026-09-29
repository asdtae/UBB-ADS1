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
    int n = 0, timeOut = 0;
    int targetPid = 0;;

    getN(n);
    getN(timeOut);

    Process* p = new Process[n];

    for (int i = 0; i < n; i++)
    {
        cin >> p[i].pid >> p[i].time;
    }

    cin >> targetPid;

    int targetTime = 0;
    for(int i = 0; i < n; ++i)
    {
        if(p[i].pid == targetPid)
        {
            targetTime = p[i].time;
            break;
        }
    }

    Queue* q = Create();
    for (int i = 0; i < n; ++i)
    {
        Enqueue(q, p[i]);
    }

    delete[] p;

    long long currTime = 0;

    while (!IsEmpty(q))
    {
        Process p = Dequeue(q);

        int execTime;
        if (p.time > timeOut)
        {
            execTime = timeOut;
        }
        else
        {
            execTime = p.time;
        }

        currTime += execTime;
        p.time -= execTime;

        if (p.time > 0)
        {
            Enqueue(q, p);
        }
        else
        {
            if (p.pid == targetPid)
            {
                cout << currTime - targetTime << endl;
                break;
            }
        }
    }

    // CLEANUP
    Destroy(q);
}