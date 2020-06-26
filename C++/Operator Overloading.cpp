//Problem: https://www.hackerrank.com/challenges/operator-overloading/problem


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Matrix {
    public:
        vector<vector<int>> a;
    
        Matrix() = default;
        ~Matrix() = default;
    
    Matrix operator+(const Matrix &m) {
        for (size_t r = 0; r < this->a.size(); ++r) {
            for (size_t c = 0; c < this->a.at(r).size(); ++c) {
                this->a.at(r).at(c) += m.a.at(r).at(c);
            }
        }
        return *this;
    }

};

int main () {
   int cases,k;
   cin >> cases;
   for(k=0;k<cases;k++) {
      Matrix x;
      Matrix y;
      Matrix result;
      int n,m,i,j;
      cin >> n >> m;
      for(i=0;i<n;i++) {
         vector<int> b;
         int num;
         for(j=0;j<m;j++) {
            cin >> num;
            b.push_back(num);
         }
         x.a.push_back(b);
      }
      for(i=0;i<n;i++) {
         vector<int> b;
         int num;
         for(j=0;j<m;j++) {
            cin >> num;
            b.push_back(num);
         }
         y.a.push_back(b);
      }
      result = x+y;
      for(i=0;i<n;i++) {
         for(j=0;j<m;j++) {
            cout << result.a[i][j] << " ";
         }
         cout << endl;
      }
   }  
   return 0;
}
