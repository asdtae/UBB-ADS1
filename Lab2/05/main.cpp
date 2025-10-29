/*
Mathe Ruben-Jonathan
512/1
Lab2/05

Kijelentés:
    Bontsunk törzstényezőkre egy adott n természetes számot!
*/
/*
#define Black "\033[30m"
#define Red "\033[31m"
#define Green "\033[32m"
#define Yellow "\033[33m"
#define Blue "\033[34m"
#define Magenta "\033[35m"
#define Cyan "\033[36m"
#define White "\033[37m"

#define Bright_Black "\033[90m"
#define Bright_Red "\033[91m"
#define Bright_Green "\033[92m"
#define Bright_Yellow "\033[93m"
#define Bright_Blue "\033[94m"
#define Bright_Magenta "\033[95m"
#define Bright_Cyan "\033[96m"
#define Bright_White "\033[97m"
*/

#include <iostream>

using namespace std;

int main()
{
    unsigned long long numb, i=2, lastDiv=-1;
    bool first = true;

    cin >> numb;

    for(i=2; i*i <= numb; i++)
    {
        unsigned long cnt=0;
        while(numb%i==0)
        {
            numb /= i;
            cnt++;
        }
        if(cnt > 0)
        {
            if(!first) cout << "*";
            cout<<i;
            if(cnt > 1) cout << "^" << cnt;
            first = false;
        }
    }

    if(numb > 1)
    {
        if(!first) cout << "*";
        cout << numb;
    }

    return 0;
}
/*
 *  TEST0:  1736
 *   OUT0:  2^1*4^1*7^1*31
 *   OUT1:  2*4*7*31
 *   OUT2:  2^3*7*31
 *   OUT3:  2^3*7
 *   OUT4:  2^3*7*31
 */
