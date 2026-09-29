#pragma once
#define ERROR '0'

struct charArray;

charArray* Create_C(int);
void Destroy_C(charArray*);

char GetElement_C(charArray*, int);
void SetElement_C(charArray*, int, char);

void Inp_C(charArray*);
void Print_C(charArray*);

