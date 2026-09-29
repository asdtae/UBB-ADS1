#pragma once
#include <vector>

using namespace std;

struct Hashtable{};

Hashtable* Create(int);
void Destroy(Hashtable*);

void Insert(Hashtable*, unsigned long long int);
void Delete(Hashtable*, unsigned long long int);

bool Find(Hashtable*, unsigned long long int);
int Size(Hashtable*);

void print(Hashtable*);

