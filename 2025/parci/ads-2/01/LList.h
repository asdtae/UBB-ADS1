#pragma once

struct LList;

LList* Create();
void Destroy(LList*);

void Insert(LList*, int);
void Delete(LList*, int);

void DelSub50(LList*);

void Print(LList*);