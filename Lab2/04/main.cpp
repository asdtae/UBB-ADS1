/*
Mathe Ruben-Jonathan
512/1
Lab2/04

Kijelentés:
    Adott egy 𝑛 arab szám, írjuk ki római számjegyekkel!
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

void arab2roman(int &numb, char s[101])
{
    int transc[4]={0}, i=0;



    for(; i>=0; i--)
    {
        transc[i] = numb%10;
        numb /= 10;
    }
}

int main()
{
    int numb;
    char s[101]={""};
    //char CLionBugWorkaround;

    cin >> numb;

    arab2roman(numb,s);

    cout << s;

    //cin >> CLionBugWorkaround;

    return 0;
}

/*
 *  I   -   1
 *  V   -   5
 *  X   -   10
 *  L   -   50
 *  C   -   100
 *  D   -   500
 *  M   -   1000
 *
 *  TEST0:  1492
 *    OUT:
 */