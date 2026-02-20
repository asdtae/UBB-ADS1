#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    unsigned long long int data;
    Node* next;
};

struct HashNode
{
    Node* entry;
    HashNode* next;
};

struct Hashtable
{
    HashNode* head;
    int size;
    int nrOfItems;
};

int getHash(const unsigned long long int x, const int size)
{
    unsigned long long int hash = 5053;

    hash += x;

    return (hash%size) ;
}

Node* CreateNode(unsigned long long int data)
{
    Node* p = new Node();

    p->next = nullptr;
    p->data = data;

    return p;
}

void DeleteNode(Node* p)
{
    if (p->next != nullptr)
    {
        DeleteNode(p->next);
    }

    delete p;
}

HashNode* CreateHashNode()
{
    HashNode* h = new HashNode();

    h->next = nullptr;
    h->entry = nullptr;

    return h;
}

void DeleteHashNode(HashNode* h)
{
    if (h->next != nullptr)
    {
        if (h->entry != nullptr)
        {
            DeleteNode(h->entry);
        }

        DeleteHashNode(h->next);
    }

    delete h;
}

Hashtable* Create(const int size)
{
    Hashtable* h = new Hashtable();

    h->head = nullptr;
    h->size = size;
    h->nrOfItems = 0;

    HashNode* p = CreateHashNode();

    for (int i = 1; i<size; i++)
    {
        HashNode* q = CreateHashNode();

        p->next = q;

        p = p->next;
    }

    return h;
}

void Destroy(Hashtable* h)
{
    if (h->head != nullptr)
    {
        DeleteHashNode(h->head);
    }

    delete h;
}

bool Find(Hashtable* h, unsigned long long int x)
{
    int hash = getHash(x,h->size);

    HashNode* q = h->head;

    if (h->head!=nullptr)
    {
        for (int i = 0; i<hash-1; i++)
        {
            q = q->next;
        }

        if (q->entry != nullptr)
        {
            Node* p = q->entry;
            while (p->next != nullptr)
            {
                if (p->data == x) return true;

                p = p->next;
            }
        }
    }

    return false;
}

void Insert(Hashtable* h, unsigned long long int x)
{
    int hash = getHash(x,h->size);

    if (!Find(h,x))
    {
        HashNode* q = h->head;

        if (h->head!=nullptr)
        {
            for (int i = 0; i<hash-1; i++)
            {
                q = q->next;
            }

            if (q->entry == nullptr)
            {
                Node* p = CreateNode(x);
                q->entry = p;
            }
            else
            {
                Node* p = q->entry;
                while (p->next != nullptr) p = p->next;

                Node* r = CreateNode(x);
                p->next = r;
            }
        }

        h->nrOfItems ++;
    }
}

void Delete(Hashtable* h, unsigned long long int x)
{
    int hash = getHash(x,h->size);

    if (!Find(h,x))
    {
        HashNode* q = h->head;

        if (h->head!=nullptr)
        {
            for (int i = 0; i<hash-1; i++)
            {
                q = q->next;
            }

            if (q->entry != nullptr)
            {
                Node* p = q->entry;
                if (p->data == x)
                {
                    q->entry = p->next;

                    delete p;
                }
                else
                {
                    while (p->next != nullptr && p->data != x) p = p->next;

                    if (p->next == nullptr)
                    {
                        Node* r = q->entry;
                        while (r->next->next != nullptr) r = r->next;

                        r->next = nullptr;
                        delete p;
                    }
                    else
                    {
                        Node* r = p->next;

                        p->data = r->data;
                        p->next = r->next;

                        delete r;
                    }
                }
            }
        }

        h->nrOfItems --;
    }
}

void print(Hashtable* h)
{
    HashNode* p = h->head;

    for (int i= 0; i<h->size; i++)
    {
        if (p->entry != nullptr)
        {
            Node *q = p->entry;
            while (q->next!=nullptr)
            {
                cout<< q->data << ' ';
                q = q->next;
            }
        }
    }
}


int Size(Hashtable* h)
{
    return h->nrOfItems;
}