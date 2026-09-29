#include <iostream>
#include <fstream>

using namespace std;

bool prim(int a)
{
    if(a == 1) return false;

    return true;
}

int fela()
{
    int n,i;
    int parosEset=0, paratlanEset=0;
    ifstream fin("tests.in");

    fin >> n;

    int a[n];
    int b[n];
    for(i=0; i<n; i++) b[n] = 0;

    for(i=0; i<n; i++)
    {
        fin >> a[i];
        if(a[i]%2==0)
        {
            a[i] = 0;
            parosEset++;
        }
        else if(!prim(a[i]))
        {
            paratlanEset++;
        }

        if(parosEset>=2) return 0;
        if(paratlanEset>=2) return 2;
    }
}

int main()
{
    cout << fela();

    int n;
    cin >> n;

    return 0;
}
