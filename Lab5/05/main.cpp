/*
*  Mathe Ruben-Jonathan
 *  512
 *  Lab5/05
 *
 *  Kijelentes:
 *  Adott egy kifejezes fordıtott lengyel formaban.
 *  Irjatok alkalmazast, amely kiertekeli a kifejezest.
 */

#include <iostream>
#include <cstring>
#include "Stack.h"

using namespace std;

void getN(int &n)
{
    cin >> n;
}

bool isOp(const char* s)
{
    if (strlen(s) > 1) return false;

    const char c = s[0];
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

long long int calc(char op, long long int op1, long long int op2)
{
    switch (op)
    {
        case '+': return op1 + op2;
        case '-': return op1 - op2;
        case '*': return op1 * op2;
        case '/': return op1 / op2;
        default: return 0;
    }
}

int main()
{
    // INIT
    Stack* s = Create();
    char buff[2048];

    if (cin.getline(buff, sizeof(buff)))
    {
        char* c = strtok(buff, " ");

        while (c != nullptr)
        {
            if (isOp(c))
            {
                long long int op2 = Pop(s);
                long long int op1 = Pop(s);

                long long int res = calc(c[0], op1, op2);
                Push(s, res);
            }
            else
            {
                long long int num = atoll(c);
                Push(s, num);
            }

            c = strtok(nullptr, " ");
        }
    }

    // OUT
    cout<<Pop(s)<<endl;

    // CLEANUP
    Destroy(s);
}