#pragma once
#define type long int

struct LList;

LList* Create();
void Destroy(LList*);

void Insert(LList*, type);
void Delete(LList*, type);

int DelByDiv(LList*, int, int);
void Print(LList*);

