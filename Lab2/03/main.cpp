/*
Mathe Ruben-Jonathan
512/1
Lab2/01

Kijelentés:
    Adott egy római szám, írjuk ki arab számjegyekkel!
*/

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


#include <iostream>
#include <cstring>

using namespace std;

void roman2arab(char s[101], int translatedCString[100])
{
    int i=0;

    while(strcmp(&s[i],"")!=0)
    {
        printf("%s%c%s, ",Bright_Yellow,s[i],White);



        i++;
    }

    printf("\n");
}

int main()
{
    char s[101]={""};
    int temp_convert[100];
    char CLionBugWorkaround;
    unsigned long long numb = 0;

    cin >> s;
..
    roman2arab(s,temp_convert);

    cout << "A megadott szam arab szamjegyekkel: " << numb;

    cin >> CLionBugWorkaround;

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
 *  TEST0:  MMMCDXCIX
 *    OUT:
 */