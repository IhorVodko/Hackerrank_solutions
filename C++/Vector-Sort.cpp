#Problem: https://www.hackerrank.com/challenges/vector-sort/problem


#include <vector>
#include <iostream>
using namespace std;


int main() {

    vector<int> v;
    size_t t{};
    int i, j{};

    cin >> t;
    while (cin >> i) {v.push_back(i); }
  
    sort(v.begin(), v.end());
  
    for (const auto &num: v)
        cout << num << ' ';
 
    return 0;
}
