#include <iostream>
#define type double

using namespace std;

struct Node
{
    type data;
    Node* next;
};

Node* CreateNode(const type x)
{
    Node* p = new Node;

    p->data = x;
    p->next = nullptr;
    return p;
}

struct LList
{
    Node *head;
};

LList* Create()
{
    LList *v = new LList;
    v->head = nullptr;
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

void Destroy(LList* v)
{
    DestroyNode(v->head);
    delete v;
}

bool isEmpty(const LList* v)
{
    return v->head == nullptr;
}

void Insert_Sorted(LList* v, const type x)
{
    if(isEmpty(v))
    {
        v->head = CreateNode(x);
    }
    else
    {
        Node *p = CreateNode(x);
        Node *q = v->head;

        while(q->data <= x && q->next != nullptr) q = q->next;
        if (q->data > x)
        {
            p->data = q->data;
            q->data = x;
            p->next = q->next;
            q->next = p;
        }
        else
        {
            q->next = p;
        }


    }
}

void Print(const LList* v)
{
    Node *p = v->head;
    while(p != nullptr)
    {
        cout<<p->data<<' ';
        p = p->next;
    }
}