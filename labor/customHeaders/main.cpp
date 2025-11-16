#include <iostream>

#include "IntArray.h"
#include "rbxio.h"
#include "rbxerr.h"

using namespace std;

int main()
{
    // rbxio fin()/fout() test
    char ch[100];
    fin("in",ch);
    fout("out",ch);

    // io test
    int a = 90;
    in(a);
    out(a);

    char b[10];
    in(b);
    out(b);

//    error(3,"testttt");

    /*
    IntArray* V = Create(15);
    cout << GetElement(V, 5) << endl;

    error(1,"pelda");

    SetElement(V, 3, 18);
    SetElement(V, 6, -18);

    Print(V);
    Destroy(V);
    */

    char s[90];
    gets(s);
    gets(s);

    return 0;
}
