/*
Mathe Ruben-Jonathan
512/1
Lab1/08

Kijelentés:
    Számítsuk ki hány szökőév volt/lesz két évszám között, mindkét évszámot beleszámítva!

*/

#include <iostream>

using namespace std;
/*
bool szokoev(unsigned long long int ev)
{
    if(ev%4==0 && ev%100!=0 || ev%400==0) return true;
    else return false;
}
*/
int main()
{
    unsigned long long int ev1, ev2;
    unsigned long long int eredmeny1=0,eredmeny2=0;

    cin >> ev1 >> ev2;

    if(ev1==0) ev1++;

    eredmeny1 = ((ev1-1) / 4 ) + ((ev1-1) / 400);
    eredmeny1 = eredmeny1 - ((ev1-1) / 100);

    //cout << "ev1: " << eredmeny1 << '\n';

    eredmeny2 = ev2 / 4 + ev2 / 400;
    eredmeny2 = eredmeny2 - (ev2 / 100);

    //cout << "ev1: " << eredmeny2 << '\n';

    eredmeny2 -= eredmeny1;

    if(ev1==0) eredmeny2++;

    cout << eredmeny2;

    return 0;
}