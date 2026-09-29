/*
Mathe Ruben-Jonathan
512/1
Lab1/03

Kijelentés:
 Olvassunk be a billentyuzetrol harom 64-bites elojeles egesz szamot.
 Irjuk ki oket novekvo sorrendben! Ne rendezzuk a szamokat, csak irjuk ki a kert sorrendben.
 Egymas utani elagazasok helyett, egymasba agyazottakat alkalmazzunk.
*/

#include <iostream>

using namespace std;

int main()
{
    long long int numb1, numb2, numb3;

    cin >> numb1 >> numb2 >> numb3;

    if(numb1 < numb2)
    {
        if(numb1 < numb3)
        {
            if(numb2 < numb3)
            {
                cout << numb1 << ' ' << numb2 << ' ' << numb3;
            }
            else
            {
                cout << numb1 << ' ' << numb3 << ' ' << numb2;
            }
        }
        else
        {
            cout << numb3 << ' ' << numb1 << ' ' << numb2;
        }
    }
    else
    {
        if(numb1 < numb3)
        {
            cout << numb2 << ' ' << numb1 << ' ' << numb3;
        }
        else
        {
            if(numb2 < numb3)
            {
                cout << numb2 << ' ' << numb3 << ' ' << numb1;
            }
            else
            {
                cout << numb3 << ' ' << numb2 << ' ' << numb1;
            }
        }
    }

    return 0;
}