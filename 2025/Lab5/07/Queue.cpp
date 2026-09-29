#include <iostream>

using namespace std;

struct Process
{
    int pid;
    int time;
};

struct Node {
    Process data;
    Node* next;
};

struct Queue {
    Node* front;
    Node* rear;
};

bool IsEmpty(Queue* q)
{
    return (q->front == nullptr);
}

Queue* Create()
{
    Queue* q = new Queue;
    q->front = nullptr;
    q->rear = nullptr;
    return q;
}

void Enqueue(Queue* q, Process x)
{
    Node* p = new Node;
    p->data = x;
    p->next = nullptr;

    if (q->rear == nullptr)
    {
        q->front = p;
        q->rear = p;
    }
    else
    {
        q->rear->next = p;
        q->rear = p;
    }
}

Process Dequeue(Queue* q)
{
    if (q->front == nullptr)
    {
        return {0, 0};
    }

    Node* p = q->front;
    Process res = p->data;

    q->front = p->next;

    if (q->front == nullptr)
    {
        q->rear = nullptr;
    }

    delete p;
    return res;
}

void Destroy(Queue* q)
{
    while (!IsEmpty(q))
    {
        Dequeue(q);
    }
    delete q;
}