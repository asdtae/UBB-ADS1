/*
Mathe Ruben-Jonathan
512/1
Lab2/07

Kijelentés:
    Határozzuk meg két szám összegét!
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

int add(int &i, int &j, const char numbs1[100000], const char numbs2[100000], char result[200000])
{
    int carry=0, sum, k=0;
    i--;
    j--;

    while(i>=0 || j>=0 || carry>0)
    {
        int numb1, numb2;
        numb1 = (i >= 0) ? numbs1[i] - '0' : 0;
        numb2 = (j >= 0) ? numbs2[j] - '0' : 0;

        sum = numb1 + numb2 + carry;

        result[k] = '0' + sum%10;
        carry = sum / 10;

        k++;
        i--;
        j--;
    }

    return k;
}

int main()
{
    int digits1, digits2, i=0;
    char numbs1[100000]={0}, numbs2[100000]={0};
    char result[200000]={0};

    cin >> digits1 >> numbs1;
    cin >> digits2 >> numbs2;

    i = add(digits1,digits2,numbs1,numbs2,result);

    //cout << i << endl;

    for(i--; i>=0; i--)
    {
        cout << result[i];
    }

    return 0;
}

/*
 *  TEST0:  3 123 3 456
 *   OUT0:  +)'
 *   OUT1:  464+
 *   OUT2:  579
 */
