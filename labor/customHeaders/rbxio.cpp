#include "rbxio.h"

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

#include <cstdio>
#include <iostream>

#ifndef error
    #include "rbxerr.h"
#endif

void fin(const char *filename, char *s)
{
    FILE *InFile = fopen(filename, "r");

    if(InFile != nullptr)
    {
        fgets(s,100,InFile);
    }
    else error(1,"fin/fopen()");

    fclose(InFile);
}

void fout(const char *filename, const char *s)
{
    FILE *OutFile = fopen(filename, "w");

    if(OutFile != nullptr)
    {
        fprintf(OutFile,"%s",s);
    }
    else error(1,"fout/fopen()");

    fclose(OutFile);
}

void in(int &ret)
{
    std::cin >> ret;
}

void out(int &ret)
{
    std::cout << ret << '\n';
}

void in(char *ret)
{
    std::cin >> ret;
}

void out(char *ret)
{
    std::cout << ret << '\n';
}