#pragma once
#define type long int

struct LList;

LList* Create();
void Destroy(LList*);

void Insert_Sorted(LList*, type);
void Shift(LList*, int);

void Print(const LList*);