//Problem: https://www.hackerrank.com/challenges/arrays-introduction/problem?h_r=next-challenge&h_v=zen
//using dynamic memory allocation

#include <iostream>
using namespace std;


int main() {

    int t{}, i{};

    cin >> t;
    int * pntr = new int[t];
    while(cin >> pntr[i++]);
    while(cout << pntr[--t] << " " && t);
    delete [] pntr;

    return 0;
}
