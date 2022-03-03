/* Copyright 2022 CSCE350 */

#include "../inc/extracredit.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
#include <cmath>

using std::clock;
using std::clock_t;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::pow;
using std::string;
using std::to_string;
using std::vector;

int main(int argc, char *argv[])
{
    for (int i = 1; i < 6; ++i)
    {
        ofstream myfile;
        myfile.open("output/output-" + to_string((int)pow(10, i)) + ".txt");
        double sum = 0.0;
        for (int j = 0; j < 100; ++j)
        {
            clock_t start, end;
            vector<float> list;
            getInput("inputs/input-" + to_string((int)pow(10, i)) + "-" + to_string(j) + ".txt", &list);
            start = clock();
            quicksort(&list, 0, static_cast<int>(list.size() - 1));
            end = clock();
            myfile << (double(end - start) / double(CLOCKS_PER_SEC)) << " ";
            sum += (double(end - start) / double(CLOCKS_PER_SEC));
        }
        myfile.close();
        cout << "Average " << ((int)pow(10, i)) << ": " << (sum / 100) << endl;
    }
    return 0;
}

void quicksort(vector<float> *list, int left, int right)
{
    float pivot = (*list).at(left);
    int j = right;
    int i = left + 1;

    for (; i < j; ++i)
    {
        if ((*list).at(i) > pivot)
        {
            for (; j > i; --j)
            {
                if ((*list).at(j) < pivot)
                {
                    swap(list, i, j);
                    break;
                }
            }
        }
    }
    if ((*list).at(j) < pivot)
    {
        swap(list, left, j);
        if (j - 1 > left)
        {
            quicksort(list, left, j - 1);
        }
        if (j + 1 < right)
        {
            quicksort(list, j + 1, right);
        }
    }
    else
    {
        swap(list, left, j - 1);
        if (j - 2 > left)
        {
            quicksort(list, left, j - 2);
        }
        if (j < right)
        {
            quicksort(list, j, right);
        }
    }
}

void swap(vector<float> *v, int i, int j)
{
    std::iter_swap((*v).begin() + i, (*v).begin() + j);
}

void getInput(string file_name, vector<float> *input)
{
    ifstream myfile;
    myfile.open(file_name);
    if (myfile.is_open())
    {
        string space_delimiter = " ";

        size_t pos = 0;
        string line;
        getline(myfile, line);
        while ((pos = line.find(space_delimiter)) != string::npos)
        {

            (*input).push_back(std::stof(line.substr(0, pos)));
            line.erase(0, pos + space_delimiter.length());
        }
        (*input).push_back(std::stof(line));
    }
    else
    {
        cout << "Error, could not open file\n";
    }
    myfile.close();
}