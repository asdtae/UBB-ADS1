#include <iostream>
using namespace std;

struct Node
{
    int data;
    int poz;
    Node* next;
};

Node* CreateNode(int x, int k)
{
    Node* p = new Node;

    p->data = x;
    p->poz = k;
    p->next = nullptr;

    return p;
}

struct Queue
{
    Node* top;
};

Queue* Create()
{
    Queue* v = new Queue;
    v->top = nullptr;

    return v;
}

bool IsEmpty(Queue* v)
{
    return (v->top == nullptr);
}

void DestroyNode(Node* p)
{
    if(p != nullptr)
    {
        DestroyNode(p->next);
        delete p;
    }
}

void Destroy(Queue* v)
{
    if(!IsEmpty(v))
    {
        DestroyNode(v->top);
        delete v;
    }
}

void Push(Queue* v, int x, int k)
{
    if(IsEmpty(v))
    {
        v->top = CreateNode(x,k);
    }
    else
    {
        Node* p = CreateNode(x,k);
        Node* q = v->top;

        while(q->next != nullptr) q = q->next;

        q->next = p;
    }
}

void Pop(Queue* v)
{
    if(!IsEmpty(v))
    {
        Node* p = v->top;
        Node* q = v->top;

        if(p->next != nullptr && v->top == p)
        {
            q = p->next;
            v->top = q;
            delete p;
            p = q;
        }
        else if(p->next == nullptr && v->top == p)
        {
            v->top = nullptr;
            delete p;
        }
    }
}

long int Front(Queue* v)
{
    if(!IsEmpty(v))
    {
        Node* p = v->top;
        return p->data;
    }

    return -1;
}

int Size(Queue* v)
{
    int size = 0;
    if(!IsEmpty(v))
    {
        Node* p = v->top;
        while(p != nullptr)
        {
            size++;
            p = p->next;
        }
    }
    else return 0;

    return size;
}

void Print(Queue* v)
{
    if(!IsEmpty(v))
    {
        Node* p = v->top;
        while(p != nullptr)
        {
            cout << p->data << ' ';
            p = p->next;
        }
    }
}