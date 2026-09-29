#include <iostream>
#define type long long int

using namespace std;

struct Node
{
    type data;
    Node* next;
};

Node* CreateNode(type x)
{
    Node* p = new Node;

    p->data = x;
    p->next = nullptr;

    return p;
}

struct Stack
{
    Node* top;
};

Stack* Create()
{
    Stack* s = new Stack;
    s->top = nullptr;

    return s;
}

void DeleteNode(Node* p)
{
    if(p != nullptr)
    {
        DeleteNode(p->next);
        delete p;
    }
}

void Destroy(const Stack* s)
{
    DeleteNode(s->top);
    delete s;
}

void Push(Stack* s, type x)
{
    Node* p = CreateNode(x);

    p->next = s->top;
    s->top = p;
}

type Pop(Stack* s)
{
    if(s->top != nullptr)
    {
        Node* p = s->top;
        s->top = p->next;

        type tmp = p->data;
        delete p;
        return tmp;
    }
}

void Print(Stack* s)
{
    if(s->top != nullptr)
    {
        Node* p = s->top;
        while(p != nullptr)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
}