//Problem: https://www.hackerrank.com/challenges/vector-erase/problem


#include <vector>
#include <iostream>
using namespace std;

int main() {

    vector<int> v;
    size_t t;
    int temp{}, b{}, e{};

    cin >> t;
    for (size_t i = 0; i < t; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }

    cin >> b;
    v.erase(begin(v) + b - 1);

    cin >> b >> e;
    v.erase(begin(v) + b - 1, begin(v) + e - 1);

    cout << v.size() << endl;

    for (auto num: v)
        cout << num << ' ';
    cout << endl;

    return 0;
}
