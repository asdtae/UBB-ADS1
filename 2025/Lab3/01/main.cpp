#include <iostream>
#define DEBUG false
#if DEBUG
#include <ctime>
#endif

using namespace std;

unsigned int inp(unsigned int &n)
{
    cin >> n;
    return n;
}

void outp(unsigned int &n)
{
    cout << n;
}

unsigned int minDiv(unsigned int n)
{
    if(n%2 == 0) return 2;
    if(n%3 == 0) return 3;

    for(unsigned long int i = 5; (uint64_t)i*i <= n; i += 6)
    {
        if(n%i == 0) return i;
        if(n%(i+2) == 0) return i+2;
    }

    return n;
}

int main()
{
    unsigned int n;

    inp(n);

    #if DEBUG
        clock_t before = clock();
    #endif
    n = minDiv(n);
    #if DEBUG
        clock_t after = clock();
    #endif

    outp(n);

    #if DEBUG
        printf("\ntime: %lf", (double)(after-before)/CLOCKS_PER_SEC);

        char s[11];
        fgets(s,10,stdin);
        fgets(s,10,stdin);
    #endif

    return 0;
}
