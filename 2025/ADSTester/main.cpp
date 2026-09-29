#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <random>
#include <vector>
#include <limits>
#include <cstdlib>

using namespace std;

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

void alszamok()
{
    int n;
    char dump[2];
    int alSzam[101] = {0};
    int maxi=INT32_MIN, temp;
    int maxi_poz[100] ={0};
    int i=1;

    ifstream getSzamoklol("./labs/L1");

    while(!getSzamoklol.eof())
    {
        getSzamoklol >> n >> dump;
        printf("%s%d%s\n",Bright_Cyan,n,Bright_White);

        while(n!=0)
        {
            temp = n%100;
            n /= 10;
            if(temp/10!=0) alSzam[temp]++;
            if(alSzam[temp] > maxi)
            {
                maxi = alSzam[temp];
                maxi_poz[0] = temp;

                for(int i=1; i<100; i++) maxi_poz[i] =0;
                i=1;
            }
            else if(alSzam[temp] == maxi)
            {
                maxi_poz[i] = temp;
                i++;
            }
            cout<<temp<<' ';
        }
        printf("\n");
    }

    cout<<endl<<endl;

    for(int i : maxi_poz)
    {
        if(i==-1) break;
        if(i!=0) cout<<i<<' ';
    }
    cin>>n;
}

int getLabId(char *input)
{
    char labNr[3];
    char idkNr[3];

    if(strstr(input,"lab"))
    {
        strcpy(labNr,input+4);
        cout<<"getLabId: return 1"<<endl;
        return 1;
    }

    if(strstr(input,"L"))
    {
        if(strcmp(input,"L10") == 0)
        {
            cout<<"getLabId: return 2 L10"<<endl;
            return 2;
        }
        if(strstr(input,"L10"))
        {
            cout<<"getLabId: return 3 L10"<<endl;
            return 3;
        }

        if(input[3] == '\0')
        {
            cout<<"getLabId: return 2 \\0"<<endl;
            return 2;
        }

        strcpy(labNr,input+1);
        strcpy(idkNr,input+3);

        cout<<labNr<<' '<<idkNr<<endl;
        cout<<"getLabId: return 3"<<endl;
        return 3;
    }

    cout<<"getLabId: return -1"<<endl;
    return 3;
}

void drawUI() {
    // Control variables
    char inputBuffer[50];
    bool escapeByUser = false;

    // Load da config
    char CONFIG_CURRENT_SEMESTER;
    char labs[100][5] = {""};
    int CONFIG_L1_LABS[10];

    char dump[100];
    int getConfigLabIterator = 0;

    ifstream getConfig("config");

    getConfig >> dump >> dump >> CONFIG_CURRENT_SEMESTER >> dump;
    getConfig >> labs[0] >> dump;

    for(getConfigLabIterator = 0; getConfigLabIterator < 10; getConfigLabIterator++)
    {
        getConfig >> CONFIG_L1_LABS[getConfigLabIterator];
    }

    getConfig >> labs[1] >> dump >> dump;

    // Title random color generator
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> randDist(0, 15);

    const char* colors[16] = {
            Black, Red, Green, Yellow, Blue, Magenta, Cyan, White,
            Bright_Black, Bright_Red, Bright_Green, Bright_Yellow,
            Bright_Blue, Bright_Magenta, Bright_Cyan, Bright_White
    };
    string title_color = colors[randDist(mt)];

    // Title
    string
            title=
    "d8888 8888888b.   .d8888b.       888                     888                                                     \n"
    "d88888 888  \"Y88b d88P  Y88b      888                     888                                                   \n"
    "d88P888 888    888 Y88b.           888                     888                                                   \n"
    "d88P 888 888    888  \"Y888b.        888888 .d88b.  .d8888b  888888 .d88b.  888d888                              \n"
    "d88P  888 888    888     \"Y88b.      888   d8P  Y8b 88K      888   d8P  Y8b 888P\"                              \n"
    "d88P   888 888    888       \"888      888   88888888 \"Y8888b. 888   88888888 888     \\    / /|                \n"
    "d8888888888 888  .d88P Y88b  d88P      Y88b. Y8b.          X88 Y88b. Y8b.     888     \\  /   |                  \n"
    "d88P     888 8888888P\"   \"Y8888P\"        \"Y888 \"Y8888   88888P\'  \"Y888 \"Y8888  888     \\/    |          \n";


    string separator = "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
    printf("%s%s %s%s",title_color.c_str() ,title.c_str(), separator.c_str(), Bright_White);

    // Main UI
    while (!escapeByUser) {

        // Get a random color and print the title
        title_color = colors[randDist(mt)];
        printf("%s> ",Bright_White);

        // is the user input valid?
        if (fgets(inputBuffer, sizeof(inputBuffer), stdin) != nullptr) {
            inputBuffer[strcspn(inputBuffer, "\n")] = '\0';

            // yes -> input interpreter
            if (strcmp(inputBuffer, "e") == 0) escapeByUser = true;
            else if (strcmp(inputBuffer, "cl") == 0) {
                system("CLS");
                printf("%s%s %s",title_color.c_str() ,title.c_str(), separator.c_str());
            }
            else if (strcmp(inputBuffer, "help") == 0 || strcmp(inputBuffer, "?") == 0) {
                printf("%sHelp:\n", Bright_White);
                printf("%scl%s         Clears the screen.\n", Bright_Cyan, Bright_White);
                printf("%se%s          Quits the Tester.\n", Bright_Cyan,Bright_White);
                printf("%shelp%s / %s?%s   Provides information for commands.\n", Bright_Cyan, Bright_White,Bright_Cyan, Bright_White);
                printf("%slabs%s       Lists current active labs.\n", Bright_Cyan,Bright_White);
                printf("%slab%s        Lists current active lab tasks (syntax: lab %s<lab_number>%s, L%s<lab number>%s).\n", Bright_Cyan,Bright_White,White,Bright_White,White,Bright_White);
            }
            else if (strcmp(inputBuffer, "") == 0) printf("");
            else if (strcmp(inputBuffer, "labs") == 0)
            {
                for(int i=0; i< strlen(reinterpret_cast<const char *>(labs)); i++)
                {
                    char labsTemp[4];
                    strcpy(labsTemp,labs[i]);
                    if(labsTemp[2]=='_') labsTemp[2] = '\0';
                    else labsTemp[3] = '\0';
                    if(strcmp(labsTemp,"")!=0)printf("%s%s%s, ",Bright_Cyan,labsTemp,Bright_White);
                }
                printf("\n");
            }
            else if (getLabId(inputBuffer) == 1)
            {
                char selectedLab[3];
                strcpy(selectedLab, inputBuffer + 4);
                printf("%s\n", selectedLab);
                for(getConfigLabIterator = 0; getConfigLabIterator < 10; getConfigLabIterator++)
                {
                    printf("%s%d %s",Bright_Red,CONFIG_L1_LABS[getConfigLabIterator],Bright_White);
                }
                printf("\n");
            }
            else if (getLabId(inputBuffer) == 2)
            {
                char selectedLab[3];
                strcpy(selectedLab, inputBuffer + 1);
                printf("%s\n", selectedLab);
                for(getConfigLabIterator = 0; getConfigLabIterator < 10; getConfigLabIterator++)
                {
                    printf("%s%d %s lab",Bright_Red,CONFIG_L1_LABS[getConfigLabIterator],Bright_White);
                }
                printf("\n");
            }
            else if (getLabId(inputBuffer) == 3)
            {
                /*
                char selectedLab[3];
                strcpy(selectedLab, inputBuffer + 1);
                printf("%s\n", selectedLab);
                for(getConfigLabIterator = 0; getConfigLabIterator < 10; getConfigLabIterator++)
                {
                    printf("%s%d %s lab inr",Bright_Red,CONFIG_L1_LABS[getConfigLabIterator],Bright_White);
                }
                printf("\n");
                 */
            }
            else {
                printf("%s'%s%s%s' is not recognized as an internal command.%s\n", Bright_Red, Bright_White, inputBuffer, Bright_Red, Bright_White);
            }
        } else {
            // no -> error
            printf("%sError reading input.%s\n",Bright_Red,Bright_White);
        }
    }
}

int main() {
    drawUI();
    //alszamok();

    return 0;
}
