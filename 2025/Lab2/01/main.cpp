/*
Mathe Ruben-Jonathan
512/1
Lab2/01

Kijelentés:
    Bontsunk fel egy adott számot 2 hatványainak összegére!
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

void base10tobase2(unsigned long long base10, unsigned int base2[65])
{
    int i = 0, mod = 0;

    while (base10 > 0)
    {
        mod = base10 % 2;
        //printf("mod: %s%d %s,",Bright_Cyan,mod,Bright_White);
        base2[i] = mod;
        //printf("base2[i]: %s%u%s ,%s %d %s",Bright_Cyan,base2[i],Bright_White,Bright_Cyan,static_cast<int>(i),Bright_White);
        base10 /= 2;
        //printf("base10: %s%llu %s,\n",Bright_Cyan,base10,Bright_White);
        i++;
    }
}

int main()
{
    unsigned long long numb;
    unsigned int base2[65] = {0};
    //char CLionBugWorkaround;
    bool first = true;

    cin >> numb;
    base10tobase2(numb, base2);

    for(int i = 64; i >= 0; i--)
    {
        if(base2[i]!=0)
        {
            if(!first)
            {
                cout << '+';
            } else first = false;
            cout << "2^" << i;
        }

    }

    //cin >> CLionBugWorkaround >> CLionBugWorkaround;

    return 0;
}

/*
 * TEST0:   55  2^5+2^4+2^2+2^1+2^0
 *  OUT0:       2^5+2^4+2^2+2^1+2^0
 */