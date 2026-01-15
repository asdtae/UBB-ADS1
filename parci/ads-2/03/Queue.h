#pragma once

struct Queue;

Queue* Create();
void Destroy(Queue*);

void Push(Queue*, int, int);
void Pop(Queue*);
long int Front(Queue*);

int Size(Queue*);

void Print(Queue*);