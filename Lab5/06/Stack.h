#pragma once
#define type long long int

struct Stack;

Stack* Create();
void Destroy(const Stack*);

void Push(Stack*, type);
type Pop(Stack*);

void Print(Stack*);