/*
 *  Mathe Ruben-Jonathan
 *  512/2
 *  mrim2553
 *  szesszio_csut_01
 *
 */
#include <iostream>
#include <vector>

using namespace std;

int lnko(int a, int b)
{
    int tmp = 0;

    while (b!=0)
    {
        tmp = a % b;
        a = b;
        b = tmp;
    }

    return a;
}

vector<bool> primSzita(int n)
{
    vector<bool> primE;
    primE.assign(n+1,true);

    primE[0] = false;
    primE[1] = false;

    for (int i = 2; i*i <=n; i++)
    {
        if (primE[i])
        {
            int j = i*i;
            while (j <= n)
            {
                primE[j] = false;
                j += i;
            }
        }
    }

    return primE;
}

vector<int> Primek(int n, vector<bool> &primE)
{
    vector<int> primek;
    primek.push_back(0);

    for (int i = 1; i<= n; i++)
    {
        if (primE[i])
        {
            primek.push_back(i);
        }
    }

    return primek;
}

vector<int> torzs(int n)
{
    vector<bool> primE = primSzita(n);
    vector<int> primek = Primek(n,primE);

    vector<int> P;
    P.push_back(0);
    int i = 1;

    while (n!=1)
    {
        if (n % primek[i] == 0)
        {
            P.push_back(primek[i]);
            n /= primek[i];
        }
        else
        {
            i++;
        }
    }

    return P;
}

int Euler(int n, vector<int> &P)
{
    int top = n;
    int bottom = 1;

    for (int i = 1; i<=P.size(); i++)
    {
        top *= P[i] - 1;
        bottom *= P[i];
    }

    if (bottom == 0) return 0;
    return top / bottom;
}

void readN(int *n)
{
    cin >> *n;
}

void writeData(int data)
{
    cout << data;
}

int getLnkoNum(const int n)
{
    int sum = 0, tmp;

    for (int i = 1; i<=n; i++)
    {
        tmp = lnko(i,n);
        cout<< i << ' ' << tmp << endl;

        if (tmp>1) sum += 1;
    }

    return sum;
}

int main()
{
    int n;
    readN(&n);

    // Primszita Teszt
        vector<bool> prime = primSzita(n);

        for (int i = 1; i < prime.size(); i++) cout << i << ' ';
        cout << endl;

        for (int i = 1; i < prime.size(); i++) cout << prime[i] << ' ';
        cout << endl;
        cout << endl;

    // Primek teszt
        vector<int> primek = Primek(n,prime);

        for (int i = 1; i < primek.size(); i++) cout << primek[i] << ' ';
        cout << endl;
        cout << endl;

    /*
    vector<int> P = torzs(n);
    const int eul = Euler(n,P);

    const int rez = n - eul;
    writeData(rez);
    */

    return 0;
}