/*
 *  Mathe Ruben-Jonathan
 *  mrim2553
 *  512/2
 *  feladat_nev
 */
#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

// primek_bool -> primek_tomb -> torzstenyezok -> keplet -> keplet2

vector<bool> Prime(const int &n)
{
    vector<bool> p(n+1,true);  // 0...n - true
    p[0] = false;                   // 0 - false
    p[1] = false;                   // 1 - false

    for (int i=2; i<=n; i++)
    {
        p.push_back(true);
    }

    for (int i=2; i*i<=n; i++)
    {
        if (p[i] == true)
        {
            int j = i * i;
            while (j<=n)
            {
                p[j] = false;
                j += i;
            }
        }
    }

    return p;
}

vector<int> Primek(const vector<bool>& prime, const int &n)
{
    vector<int> p;

    for (int i = 2; i<=n; i++)
    {
        if (prime[i])
        {
            p.push_back(i);
        }
    }

    return p;
}

vector<int> Torzs(const vector<int>& primek, const int &n)
{
    vector<int> t;

    for (int i = 0; i<primek.size();i++)
    {
        if (n%primek[i] == 0)
        {
            t.push_back(primek[i]);
        }
    }

    return t;
}

int Euler(const vector<int>& torzs ,const int &n)
{
    int bottom = 1, top = n;

    for (int i = 0; i<torzs.size(); i++)
    {
        top *= torzs[i] - 1;
        bottom *= torzs[i];
    }

    return top/bottom;
}

int getLnko(const int &n)
{
    time_t before = clock();
    const vector<bool> prime = Prime(n);
    time_t after = clock();

    cout << "done: prime in " << static_cast<double>(after - before)/CLOCKS_PER_SEC << endl;

    before = clock();
    vector<int> primek = Primek(prime,n);
    after = clock();
    cout << "done: primek in " << static_cast<double>(after - before)/CLOCKS_PER_SEC << endl;

    before = clock();
    vector<int> torzs = Torzs(primek,n);
    after = clock();
    cout << "done: torzs in " << static_cast<double>(after - before)/CLOCKS_PER_SEC << endl;

    before = clock();
    int euler = Euler(torzs,n);
    after = clock();
    cout << "done: euler in " << static_cast<double>(after - before)/CLOCKS_PER_SEC << endl;

    return n - euler;
}

int getN()
{
    int tmp;
    cin >> tmp;
    return tmp;
}

int main()
{
    int n = getN();
    n = getLnko(n);

    cout << n;

    return 0;
}