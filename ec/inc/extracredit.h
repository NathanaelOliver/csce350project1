/* Copyright 2021 CSCE240 */
#ifndef EXTRACREDIT_H_
#define EXTRACREDIT_H_

#include <vector>
#include <string>

using std::string;
using std::vector;

void getInput(string file_name, vector<float> *input);
void quicksort(vector<float> *list, int left, int right);
void swap(vector<float> *v, int i, int j);
void print(vector<float> output, string file_name);
void output(vector<float> output);

#endif
