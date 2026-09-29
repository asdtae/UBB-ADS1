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
#include <cstring>

using namespace std;

void arab2roman(int &numb, char s[101])
{
    int i;
    struct numbs
    {
        char roman[3];
        int arab;
    } tranz[13];

    strcpy(tranz[0].roman,"I");
    tranz[0].arab = 1;
    strcpy(tranz[1].roman,"IV");
    tranz[1].arab = 4;
    strcpy(tranz[2].roman,"V");
    tranz[2].arab = 5;
    strcpy(tranz[3].roman,"IX");
    tranz[3].arab = 9;
    strcpy(tranz[4].roman,"X");
    tranz[4].arab = 10;
    strcpy(tranz[5].roman,"XL");
    tranz[5].arab = 40;
    strcpy(tranz[6].roman,"L");
    tranz[6].arab = 50;
    strcpy(tranz[7].roman,"XC");
    tranz[7].arab = 90;
    strcpy(tranz[8].roman,"C");
    tranz[8].arab = 100;
    strcpy(tranz[9].roman,"CD");
    tranz[9].arab = 400;
    strcpy(tranz[10].roman,"D");
    tranz[10].arab = 500;
    strcpy(tranz[11].roman,"CM");
    tranz[11].arab = 900;
    strcpy(tranz[12].roman,"M");
    tranz[12].arab = 1000;

    for(i=12; i>=0; i--)
    {
        while (numb >= tranz[i].arab)
        {
            numb -= tranz[i].arab;
            strcat(s,tranz[i].roman);
        }
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
 *    OUT:  MCDXCII
 */