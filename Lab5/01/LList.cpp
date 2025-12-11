#include <iostream>

using namespace std;

struct node {
    long int data;
    node* next;
};

struct LList {
    node* top;
};

LList* Create()
{
    LList* v = new LList;
    v -> top = nullptr;

    return v;
}

void Destroy(LList* v)
{
    node* p = v -> top;
    delete v;

    while(p != nullptr)
    {
        node* q = p;
        p = p -> next;
        delete p;
    }
}

void Insert(LList* v, long int x)
{
    node* p = v -> top;
    node* q = new node;
    q -> data = x;
    q -> next = nullptr;

    if(v -> top != nullptr)
    {
        while(p -> next != nullptr)
        {
            cout << p -> data << ' ';
            p = p -> next;
        }
        p -> next = q;
    }
    else
    {
        v -> top = q;
    }
}

void Delete(LList* v, long int x)
{
    ;
}

void Print(LList* v)
{
    node* p = v -> top;
    while(p != nullptr)
    {
        cout << p -> data;
        p = p -> next;
    }
}