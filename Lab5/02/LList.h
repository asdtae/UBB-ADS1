#pragma once
#define type double

struct LList;

LList* Create();
void Destroy(LList*);

void Insert_Sorted(LList*, type);

void Print(const LList*);