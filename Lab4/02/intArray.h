#pragma once
#define ERROR 0

struct intArray;

intArray* Create(int);
void Destroy(intArray*);

unsigned long long int Get(intArray*, int);
void Set(intArray*, int, unsigned long long int);

void Print(intArray*);