#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* CreateNode(int x)
{
    Node* n = new Node;
    n -> data = x;
    n -> next = nullptr;
    return n;
}

struct LList {
    Node* head;
};

LList* CreateLL()
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

void DestroyLL(LList* v)
{
    DestroyNode(v->head);
    delete v;
}

bool IsEmpty(LList* v)
{
    return v->head == nullptr;
}

void InsertLLSpec(LList* v, int x)
{
    if(IsEmpty(v)) {
        v->head = CreateNode(x);
    } else {
        Node* p = CreateNode(x);
        p -> next = v -> head;
        v -> head = p;
    }
}

void InsertLL(LList* v, int x)
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

void DeleteLL(LList* v, int x)
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
            while(p->data != x)
            {
                if(p->next != nullptr)
                {
                    q = p;
                    p = p->next;
                }
                else break;
            }
            if(p->next == nullptr)
            {
                q->next = nullptr;
                delete p;
            }
            else
            {
                q->next = p->next;
                delete p;
            }
        }
    }
}

int DelByDivLL(LList* v, int n, int numb)
{
    Node* p = v->head;
    while(p != nullptr)
    {
        if(p->data % numb == 0)
        {
            Node* q = p->next;
            // fuggvenyhivas helyett toroljem, hogy ne kezdje a keresest az elejetol
            DeleteLL(v,p->data);
            n--;
            p = q;
        }
        else p = p->next;
    }

    return n;
}

void PrintLL(LList* v)
{
    Node* p = v -> head;
    while(p != nullptr)
    {
        cout << p -> data << endl;
        p = p -> next;
    }
}