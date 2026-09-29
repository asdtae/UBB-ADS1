#include <iomanip>
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

void Insert(LList* v, type x)
{
    if(isEmpty(v))
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

LList* Merge(LList* v1, LList* v2)
{
    if (v1->head == nullptr) {
        LList* res = Create();
        res->head = v2->head;
        v2->head = nullptr;
        return res;
    }
    if (v2->head == nullptr) {
        LList* res = Create();
        res->head = v1->head;
        v1->head = nullptr;
        return res;
    }

    Node* p1 = v1->head;
    Node* p2 = v2->head;

    LList* res = Create();

    if(p1->data > p2->data)
    {
        res->head = p2;
        p2 = p2->next;
    }
    else
    {
        res->head = p1;
        p1 = p1->next;
    }

    Node* p = res->head;


    while(p1 != nullptr && p2 != nullptr)
    {
        if(p1->data > p2->data)
        {
            p->next = p2;
            p2 = p2->next;
        }
        else
        {
            p->next = p1;
            p1 = p1->next;
        }

        p = p->next;
    }

    if(p1 == nullptr) p->next = p2;
    if(p2 == nullptr) p->next = p1;

    v1->head = nullptr;
    v2->head = nullptr;

    return res;
}

void Print(const LList* v)
{
    Node *p = v->head;

    cout << setprecision(15) << fixed;

    if (p != nullptr)
    {
        cout<<p->data;
        p = p->next;
    }

    while(p != nullptr)
    {
        cout<<' '<<p->data;
        p = p->next;
    }
}