//Problem: https://www.hackerrank.com/challenges/c-tutorial-stringstream/problem


#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
    
    stringstream ss(str);
    vector<int> vec;
    char ch{};
    int temp{};

    while (ss >> temp) {
        vec.push_back(temp);
        ss >> ch;
    }
    return vec;
}
