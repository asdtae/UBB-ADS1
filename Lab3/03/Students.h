#pragma once

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct DataSet;

DataSet* Create(uint32_t);
DataSet* Create(const char*);
bool Search(DataSet*, const string&);
void Print(const DataSet*);
