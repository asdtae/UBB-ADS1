#include <iostream>
#define type long int

using namespace std;

struct Node
{
    type data;
    Node* next;
    Node* prev;
};

Node* CreateNode(const type x)
{
    Node* p = new Node;

    p->data = x;
    p->next = nullptr;
    p->prev = nullptr;
    return p;
}

struct DLList
{
    Node *head;
    Node *tail;
};

DLList* Create()
{
    DLList *v = new DLList;
    v->head = nullptr;
    v->tail = nullptr;
    return v;
}

void DestroyNode(Node* p)
{
    if(p != nullptr)
    {
        DestroyNode(p->next);
        delete p;
    }
}

void Destroy(DLList* v)
{
    DestroyNode(v->head);
    delete v;
}

bool isEmpty(const DLList* v)
{
    return v->head == nullptr;
}

void Insert_Sorted(DLList* v, const type x)
{
    Node *p = CreateNode(x);

    if(isEmpty(v))
    {
        v->head = p;
        v->tail = p;
    }
    else
    {
        Node* q = v->head;
        Node* o = v->tail;

        if (x <= q->data)
        {
            p->next = q;
            q->prev = p;
            v->head = p;
        }
        else if (x >= o->data)
        {
            o->next = p;
            p->prev = o;
            v->tail = p;
        }
        else
        {
            while(q->data < x && q->next != nullptr) q = q->next;
            o = q->prev;
            o->next = p;
            p->prev = o;

            p->next = q;
            q->prev = p;
        }
    }
}

void Shift(DLList* v, int k)
{
    
}

void Print(const DLList* v)
{
    Node *p = v->head;
    while(p != nullptr)
    {
        cout<<p->data<<' ';
        p = p->next;
    }
}