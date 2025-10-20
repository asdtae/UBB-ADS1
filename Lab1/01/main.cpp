#include <iostream>

using namespace std;

void csereSegedValtozoval(unsigned long int &a, unsigned long int &b)
{
    unsigned long int segedValtozo;

    segedValtozo = a;
    a = b;
    b = segedValtozo;
}

void csereOsszeadasKivonas(unsigned long int &a, unsigned long int &b)
{
    a += b;

}

int main()
{
    unsigned long int elsoSzam, masodikSzam;

    cin >> elsoSzam >> masodikSzam;

    csereSegedValtozoval(elsoSzam,masodikSzam);

    swap()

    cout << elsoSzam << ' ' << masodikSzam;
    return 0;
}
