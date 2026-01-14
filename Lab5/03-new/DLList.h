#pragma once
#define type long int

struct DLList;

DLList* Create();
void Destroy(DLList*);

void Insert(DLList*, type);
void Insert_Sorted(DLList*, type);
void Shift(DLList*, int);

void Print(const DLList*);