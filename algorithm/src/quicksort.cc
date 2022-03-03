/* Copyright 2022 CSCE350 */

#include "../inc/quicksort.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>

using std::clock;
using std::clock_t;
using std::cout;
using std::ifstream;
using std::ofstream;
using std::string;
using std::vector;

int main(int argc, char *argv[])
{
    clock_t start, end;
    vector<float> list;
    getInput("input.txt", &list);
    start = clock();
    quicksort(&list, 0, static_cast<int>(list.size() - 1));
    end = clock();
    cout << (double(end - start) / double(CLOCKS_PER_SEC)) << std::endl;
    print(list, "output.txt");
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

void print(vector<float> output, string file_name)
{
    ofstream myfile;
    myfile.open(file_name);
    myfile << output.at(0);
    for (int i = 1; i < output.size(); ++i)
    {
        myfile << " " << output.at(i);
    }
    myfile.close();
}