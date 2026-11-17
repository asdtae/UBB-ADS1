/*
 *  Mathe Ruben-Jonathan
 *  mrim2578
 *  511
 *  prob-PT_HaromDijazott_Info
 *
 *  Lab3/03
 *
 *  Kijelentés:
 *      Ismerjük egy osztály tanulóinak neveit (családnév + keresztnév)
 *      és év végi átlagait. Állapítsuk meg, hogy egy adott nevű tanuló
 *      az első három díjazott között van-e?
 *
 */

#include <iostream>
#include "Students.h"

#define nrOfClasses 1

using namespace std;

static string read() {
    uint32_t strLen;
    string firstName, lastName;

    cin >> strLen >> lastName >> firstName;
    return strcat(strdup(firstName.c_str()),strcat(strdup(" "),strdup(lastName.c_str())));
}

int main() {
    const auto *inp = "debug";
    DataSet *data = Create(inp);
    const string lookup = read();

    Search(data,lookup) == 0 ? cout << "nem\n" : cout << "igen\n";
    Print(data);

    return 0;
}
