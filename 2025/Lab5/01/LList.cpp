#include <iostream>
#define type long int

using namespace std;

struct Node {
    type data;
    Node* next;
};

Node* CreateNode(type x)
{
    Node* n = new Node;
    n -> data = x;
    n -> next = nullptr;
    return n;
}

struct LList {
    Node* head;
};

LList* Create()
{
    LList* v = new LList;
    v -> head = nullptr;
    return v;
}

void DestroyNode(Node* n)
{
    if(n != nullptr)
    {
        DestroyNode(n->next);
        delete n;
    }
}

void Destroy(LList* v)
{
    DestroyNode(v->head);
    delete v;
}

bool IsEmpty(LList* v)
{
    return v->head == nullptr;
}

void Insert(LList* v, type x)
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
        p->next = nullptr;
    }
}

void Insert_Sorted(LList* v, type x)
{
    if(IsEmpty(v))
    {
        v->head = CreateNode(x);
    }
    else
    {
        Node* p = CreateNode(x);
        Node* q = v->head;

        while(q->data <= x && q->next != nullptr) q = q->next;
        if(q->data > x)
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

void Delete(LList* v, type x)
{
    if(!IsEmpty(v))
    {
        Node* p = v->head;

        if(p->data == x)
        {
            v->head = p->next;
            delete p;
        }
        else
        {
            Node* q = v->head;
            while(p->data != x && p->next != nullptr)
            {
                q = p;
                p = p->next;
            }
            if(p->next == nullptr && p->data == x)
            {
                q->next = nullptr;
                delete p;
            }
            else if(p->data == x)
            {
                q->next = p->next;
                delete p;
            }
        }
    }
}

void DelByDiv(LList* v, int &n, int numb)
{
    Node* p = v->head;
    Node* q = nullptr;
    while(p != nullptr)
    {
        if (q == nullptr)
        {
            q = p;
            p = p->next;
        }
        else
        {
            if(q->data % numb == 0 && v->head == q)
            {
                v->head = q->next;
                delete q;

                q = p;
                p = p->next;
                n--;
            }
            else if(p->data % numb == 0)
            {
                q->next = p->next;
                delete p;

                p = q->next;
                n--;
            }
            else
            {
                q = p;
                p = p->next;
            }
        }
    }

    if(q != nullptr)
    {
        if(q->data % numb == 0)
        {
            delete q;
            n--;
            v->head = nullptr;
        }
    }
}

void Print(LList* v)
{
    Node* p = v -> head;
    while(p != nullptr)
    {
        cout << p -> data << endl;
        p = p -> next;
    }
}