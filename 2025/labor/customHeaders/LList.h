#pragma once

struct LList;

LList* CreateLL();
void DestroyLL(LList*);

void InsertLLSpec(LList*, int);
void InsertLL(LList*, int);
void DeleteLL(LList*, int);

int DelByDivLL(LList*, int, int);


void PrintLL(LList*);

