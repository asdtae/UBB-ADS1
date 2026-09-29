/*
 *  Mathe Ruben-Jonathan
 *  mrim2553
 *  512/2
 *  set potszesszio/02
 */
#include <iostream>
#include "hashtable.h"

#define HASHTABLE_SIZE 253

using namespace std;

int getQ()
{
    int q;
    cin >> q;
    return q;
}

void doStuff(Hashtable* h, int type)
{
    if (type == 1)
    {
        unsigned long long int x;
        cin >> x;

        Insert(h,x);
    }
    else if (type == 2)
    {
        unsigned long long int x;
        cin >> x;

        Delete(h,x);
    }
    else if (type == 3)
    {
        unsigned long long int x;
        cin >> x;

        cout << Find(h,x) << '\n';
    }
    else if (type == 4)
    {
        cout << Size(h) << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Hashtable* h = Create(HASHTABLE_SIZE);

    int q = getQ();
    for (int i = 0; i<q; i++)
    {
        int type = getQ();
        doStuff(h,type);
    }

    print(h);

    Destroy(h);
    return 0;
}