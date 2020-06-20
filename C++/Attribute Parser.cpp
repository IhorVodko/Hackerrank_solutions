//Problem: https://www.hackerrank.com/challenges/attribute-parser/problem


#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <sstream>
using namespace std;


int main() {
  
    size_t n, q;
    cin >> n >> q;

    string temp;
    vector<string> hrml;
    vector<string> quer;
    cin.ignore();

    for (size_t i=0; i<n; ++i) {
        getline(cin, temp);
        hrml.push_back(temp);
    }
    for (size_t i=0; i<n; ++i) {
        getline(cin, temp);
        quer.push_back(temp);
    }

    map<string, string> m;
    vector<string> tag;

    for (size_t i=0; i<n; ++i) {
        temp = hrml[i];
        temp.erase(remove(temp.begin(), temp.end(), '\"'), temp.end());
        temp.erase(remove(temp.begin(), temp.end(), '>'), temp.end());

        if (temp.substr(0,2) == "</") {
            tag.pop_back();
        } else {
            stringstream ss;
            ss << temp;

            string t1, p1, v1;
            char ch;
            ss >> ch >> t1 >> p1 >> ch >> v1;
            // cout << ch << ' ' <<  t1 << p1 << ch << v1 << endl;
            string temp1;

            if (tag.size() > 0) {
                temp1 = *tag.rbegin();
                temp1 = temp1 + "." + t1;
            } else {
                temp1 = t1;
            }
            tag.push_back(temp1);
            m[*tag.rbegin()+ '~' +p1] = v1;
            while (ss) {
                ss >> p1 >> ch >> v1;
                m[*tag.rbegin()+ '~' +p1] = v1;
            }

        } 

    }
    for (size_t i=0; i<q; ++i) {
        if (m.find(quer[i]) == m.end()) 
            cout << "Not Found!" << endl;
        else 
            cout << m[quer[i]] << endl;
    }
    return 0;
}
