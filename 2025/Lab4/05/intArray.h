#pragma once
#define ERROR -1

struct intArray;

intArray* Create(int);
void Destroy(intArray*);

long long int Get(intArray*, int);
void Set(intArray*, int, long long int);

void Print(intArray*);
int getN(intArray*);