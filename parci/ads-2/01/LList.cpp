#include "LList.h"

#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* CreateNode(int x)
{
    Node* p = new Node;

    p->data = x;
    p->next = nullptr;

    return p;
}

struct LList
{
    Node* head;
};

LList* Create()
{
    LList* v = new LList;
    v->head = nullptr;

    return v;
}

bool IsEmpty(LList* v)
{
    return (v->head == nullptr);
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
    if(!IsEmpty(v))
    {
        DestroyNode(v->head);
        delete v;
    }
}

void Insert(LList* v, int x)
{
    if(IsEmpty(v))
    {
        v->head = CreateNode(x);
    }
    else
    {
        Node* p = CreateNode(x);
        Node* q = v->head;

        while(q->next != nullptr) q = q->next;

        q->next = p;
    }
}

void Delete(LList* v, int x)
{
    if(!IsEmpty(v))
    {
        Node* p = v->head;
        Node* q = v->head;

        if(p->next != nullptr)
        {
            if(p->data == x && v->head == p)
            {
                q = p->next;
                v->head = q;
                delete p;
                p = q;
            }
            else p = p->next;
        }

        if(p->next == nullptr && p->data == x && v->head == p)
        {
            v->head = nullptr;
            delete p;
            p = nullptr;
        }

        while(p != nullptr)
        {
            if(p->data == x)
            {
                if(p->next == nullptr)
                {
                    q->next = nullptr;
                    delete p;
                    p = nullptr;
                }
                else
                {
                    q->next = p->next;
                    delete p;
                    p = nullptr;
                }
            }

            if(p!= nullptr && q!= nullptr)
            {
                p = p->next;
                q = q->next;
            }
        }

    }
}

void DelSub50(LList* v)
{
    if(!IsEmpty(v))
    {
        Node* p = v->head;
        while(p != nullptr)
        {
            if(p->data < 50)
            {
                Node* q = p->next;

                Delete(v,p->data);
                p = q;
            }
            else p = p->next;
        }
    }
}

void Print(LList* v)
{
    if(!IsEmpty(v))
    {
        Node* p = v->head;
        while(p != nullptr)
        {
            cout << p->data << ' ';
            p = p->next;
        }
    }
}