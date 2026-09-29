/*
*  Mathe Ruben-Jonathan
 *  512/1
 *  mrim2553
 *
 *  lab fel 3 / 2
 *
 */

#include <iostream>
#include "Queue.h"

using namespace std;

void getN(int &n)
{
    cin >> n;
}

void getData(long int &n)
{
    cin >> n;
}

void read(Queue* v, int n)
{
    int x = 0;
    while(n!=0)
    {
        cin >> x;
        Push(v,x);
        n--;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // INIT
    Queue* v = Create();
    int q = 0;
    int op = 0;
    long int tmp = 0;

    // IN
    getN(q);

    while(q!=0)
    {
        getN(op);

        if(op == 1)
        {
            getData(tmp);
            Push(v,tmp);
        }
        else if(op == 2)
        {
            Pop(v);
        }
        else if(op == 3)
        {
            cout << Front(v) << '\n';
        }
        else if(op == 4)
        {
            cout << Size(v) << '\n';
        }

        q--;
    }

    // CLEANUP
    Destroy(v);
    return 0;
}