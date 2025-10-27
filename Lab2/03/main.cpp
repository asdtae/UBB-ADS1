/*
Mathe Ruben-Jonathan
512/1
Lab2/03

Kijelentés:
    Adott egy római szám, írjuk ki arab számjegyekkel!
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

void roman2arab(const char s[101], unsigned long long &result)
{
    int i=0;
    int translatedCString[100]={0};

    while (s[i] != '\0')
    {
        //printf("%s%c%s, ",Bright_Yellow,s[i],White);

        switch(s[i])
        {
            case 'I':
                translatedCString[i] = 1;
                break;
            case 'V':
                translatedCString[i] = 5;
                break;
            case 'X':
                translatedCString[i] = 10;
                break;
            case 'L':
                translatedCString[i] = 50;
                break;
            case 'C':
                translatedCString[i] = 100;
                break;
            case 'D':
                translatedCString[i] = 500;
                break;
            case 'M':
                translatedCString[i] = 1000;
                break;
            //default:
                //printf("\n%sERROR: %s%c%s\n",Red,Bright_Red,s[i],White);
        }

        i++;
    }

    //printf("\n");

    int n = i;
    for(i=0; i<n; i++)
    {
        if(i < n - 1 && translatedCString[i] < translatedCString[i+1])
        {
            result -= translatedCString[i];
        }
        else result += translatedCString[i];
        //printf("%s%d%s, ",Bright_Green,translatedCString[i],White);
    }

    //printf("\n");
}

int main()
{
    char s[101]={""};

    //char CLionBugWorkaround;
    unsigned long long numb = 0;

    cin >> s;

    roman2arab(s,numb);

    cout << "A megadott szam arab szamjegyekkel: " << numb;

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
 *  TEST0:  MMMCDXCIX
 *    OUT:  A megadott szam arab szamjegyekkel: 3499
 */