/*
*  Mathe Ruben-Jonathan
 *  512
 *  Lab5/06
 *
 *  Kijelentes:
 *  Egy csoporton belul sztarnak nevezzuk azt a szemelyt, akit mindenki ismer,
 *  de o nem ismer senkit. Adott egy 𝑛 × 𝑛-es matrix amely n szemely ismerettsegi
 *  viszonyat mutatja (azaz 𝑎[𝑖][𝑗] = 1, ha 𝑖 ismeri 𝑗-t). Hatarozzuk meg, hogy van-e
    sztar a csoportban, es ha igen, ırjuk ki a sorszamat.
 */

#include <iostream>
#include "Stack.h"

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