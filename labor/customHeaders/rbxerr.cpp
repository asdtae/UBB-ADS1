#include "rbxerr.h"

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

void error(int errorCode, const char *in)
{
    switch (errorCode)
    {
        case 1:
            printf("%sERROR: %sin %s%s:%s Couldn't open the file.%s\n",Bright_Red,Yellow,Bright_Yellow,in,Bright_Red,Bright_White);
            perror ("File error");
            break;
        case 2:
            printf("%sERROR: %sin %s%s:%s File empty.%s\n",Bright_Red,Yellow,Bright_Yellow,in,Bright_Red,Bright_White);
            break;
        case 3:
            printf("%sERROR: %sin %s%s:%s Invalid input.%s\n",Bright_Red,Yellow,Bright_Yellow,in,Bright_Red,Bright_White);
            break;
        default:
            printf("%sERROR: %sin %serror():%s '%s%d%s' is not a valid error code.%s\n", Bright_Red, Yellow, Bright_Yellow, Bright_Red, Bright_White, errorCode, Bright_Red, Bright_White);
    }
}