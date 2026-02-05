#include <iostream>

using namespace std;

struct node
{
    long int ID;
    node *left;
    node *right;

    node *root;
};

struct tree
{
    node *head;
};

node* createNode(node* root, long int data)
{
    node* n = new node;

    n->ID = data;
    n->left = nullptr;
    n->right = nullptr;

    n->root = root;

    return n;
}

tree* Create()
{
    tree* t = new tree;

    t->head = nullptr;

    return t;
}

void destroyNode(node* n)
{
    if (n->left != nullptr) destroyNode(n->left);
    if (n->right != nullptr) destroyNode(n->right);

    delete n;
}

void Destroy(tree* t)
{
    if (t->head != nullptr) destroyNode(t->head);

    delete t;
}

void insertNode(node* n, long int data)
{
    if (n->ID > data)
    {
        if (n->left == nullptr)
        {
            node* p = createNode(n,data);
            n->left = p;
        }
        else
        {
            insertNode(n->left,data);
        }
    }
    else
    {
        if (n->right == nullptr)
        {
            node* p = createNode(n,data);
            n->right = p;
        }
        else
        {
            insertNode(n->right,data);
        }
    }
}

void Insert(tree* t, long int x)
{
    if (t->head == nullptr)
    {
        node *n = createNode(nullptr,x);
        t->head = n;
    }
    else
    {
        insertNode(t->head,x);
    }
}

void readPost(const node* root)
{
    if (root->left != nullptr) readPost(root->left);
    if (root->right != nullptr) readPost(root->right);

    cout << root->ID << ' ';
}

void ReadPost(const tree* t)
{
    if (t != nullptr)
    {
        if (t->head != nullptr)
        {
            readPost(t->head);
        }
    }
}