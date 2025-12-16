#include <iostream>

#define SIZE 13

#include "IntArray.h"
#include "rbxio.h"
#include "rbxerr.h"
#include "LList.h"
#include "HashTable.h"

using namespace std;

int main()
{
    HashTable* H = CreateHT(SIZE);

    InsertHT(H,2);
    InsertHT(H,-5);
    InsertHT(H,3);
    InsertHT(H,18);
    InsertHT(H,21);
    InsertHT(H,19);
    InsertHT(H,35);
    InsertHT(H,41);

    FindHT(H,21);

    char s[90];
    gets(s);
    gets(s);

    return 0;
}
