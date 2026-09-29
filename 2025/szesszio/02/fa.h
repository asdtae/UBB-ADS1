#pragma once

struct tree;

tree* Create();
void Destroy(tree*);

void Insert(tree*, long int);

void ReadPost(const tree*);