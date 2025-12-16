#include "LList.h"
#include <iostream>
#include <cmath>

using namespace std;

struct HashTable
{
    int size;
    LList** T;
};

HashTable* CreateHT(int N)
{
    HashTable* H = new HashTable;
    H -> size = N;
    H -> T = new LList* [N];
    for(int i=0; i<N; i++)
        H -> T[i] = CreateLL();
}
void DeleteHT(HashTable*)
{

}

int Hash(int x, int N)
{
    x = abs(x);
    x %= N;
    return x;
}

void InsertHT(HashTable* H, int x)
{
    int index = Hash(x,H->size);
    InsertLLSpec(H->T[index],x);
}
void DeleteHT(HashTable* H, int x)
{
    int index = Hash(x,H->size);
}
void FindHT(HashTable* H, int x)
{
    int index = Hash(x,H->size);
    int i = 0;


}

void Print(HashTable* H)
{

}

