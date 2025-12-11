#pragma once

struct LList;

LList* Create();
void Destroy(LList*);

void Insert(LList*, long int);
void Delete(LList*, long int);

void Print(LList*);

