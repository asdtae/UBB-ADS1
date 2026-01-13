#pragma once
#define type double

struct LList;

LList* Create();
void Destroy(LList*);

void Insert(LList*, type);
void Insert_Sorted(LList*, type);

LList* Merge(LList*, LList*);
void Print(const LList*);