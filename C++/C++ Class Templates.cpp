//Problem: https://github.com/IhorVodko/Hackerrank_solutions/new/master/C%2B%2B


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

template <typename T>
class AddElements {
    T element1;
public:
    AddElements (T arg1) {element1 = arg1; }
    T add(const T &element2) {
        return (element1 + element2);
    }
};

template <>
class AddElements<std::string> {
    std::string element1;
public:
    AddElements(std::string arg1) {element1 = arg1; }
    std::string concatenate(const std::string &element2) {
        return (element1 + element2); 
    }
};

// use this class to pass the timelimit
class Fast {
public:
    Fast() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
};

Fast fast;  // a global instance;


int main () {
  int n,i;
  cin >> n;
  for(i=0;i<n;i++) {
    string type;
    cin >> type;
    if(type=="float") {
        double element1,element2;
        cin >> element1 >> element2;
        AddElements<double> myfloat (element1);
        cout << myfloat.add(element2) << endl;
    }
    else if(type == "int") {
        int element1, element2;
        cin >> element1 >> element2;
        AddElements<int> myint (element1);
        cout << myint.add(element2) << endl;
    }
    else if(type == "string") {
        string element1, element2;
        cin >> element1 >> element2;
        AddElements<string> mystring (element1);
        cout << mystring.concatenate(element2) << endl;
    }
  }
  return 0;
}
