#pragma once
#define ERROR -1

struct intArray;

intArray* Create_I(int);
void Destroy_I(intArray*);

int GetElement_I(intArray*, int);
void SetElement_I(intArray*, int, int);

void Inp_I(intArray*);
void Print_I(intArray*);