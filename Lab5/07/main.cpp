/*
 *  Mathe Ruben-Jonathan
 *  512
 *  Lab5/07
 *
 *  Kijelentes:
 *  Adott 𝑛 folyamat. Minden folyamatnak ismerjuk az azonosıtojat (PID)
 *  es a vegrehajtashoz szukseges idoegyseget. A folyamatokat FIFO elv alapjan
 *  utemezzuk, azaz az elsonek beerkezett folyamatot hajtjuk vegre eloszor. ´Irjunk
 *  alkalmazast, amely a folyamatok utemezeset szimulalja, valamint hatarozzuk
 *  meg a folyamatok atlag varakozasi idejet
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
    Stack* s = Create();
    int n = 0, m = 0;

    getN(n);
    m = n;

    //
    int** mat = new int*[n + 1];
    for (int i = 1; i <= n; ++i)
    {
        mat[i] = new int[n + 1];
    }

    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            char c;
            cin >> c;
            mat[i][j] = c - '0';
        }
    }

    for(int i = 1; i <= n; ++i)
    {
        Push(s, i);
    }

    while(m > 1)
    {
        int a = (int)Pop(s);
        int b = (int)Pop(s);

        if (mat[a][b] == 1)
        {
            Push(s, b);
        }
        else
        {
            Push(s, a);
        }

        m--;
    }

    if (m > 0)
    {
        int cnad = (int)Pop(s);
        bool p = true;

        for(int j = 1; j <= n; ++j)
        {
            if(mat[cnad][j] == 1)
            {
                p = false;
                break;
            }
        }

        if(p)
        {
            for(int i = 1; i <= n; ++i)
            {
                if(i != cnad && mat[i][cnad] == 0)
                {
                    p = false;
                    break;
                }
            }
        }

        if(p)
        {
            cout << cnad << endl;
        }
    }

    // CLEANUP
    Destroy(s);

    for(int i = 1; i <= n; ++i)
    {
        delete[] mat[i];
    }
    delete[] mat;
}