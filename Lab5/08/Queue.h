#pragma once

struct Process
{
    int pid;
    int time;
};

struct Queue;

bool IsEmpty(Queue* q);

Queue* Create();

void Enqueue(Queue*, Process);
Process Dequeue(Queue*);

void Destroy(Queue*);