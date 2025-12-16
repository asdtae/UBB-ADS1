#pragma once

struct HashTable;

HashTable* CreateHT(int);
void DeleteHT(HashTable*);

void InsertHT(HashTable*, int);
void DeleteHT(HashTable*, int);
int FindHT(HashTable*, int);

void PrintHT(HashTable*, int);
