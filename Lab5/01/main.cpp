#include <iostream>
#include "LList.h"

using namespace std;

int main()
{
    LList* v = Create();

    Insert(v,2);

    Print(v);
    Destroy(v);

    return 0;
}
