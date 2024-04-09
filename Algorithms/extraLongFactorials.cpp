// problem: https://www.hackerrank.com/challenges/extra-long-factorials/problem?isFullScreen=true


#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'extraLongFactorials' function below.
 *
 * The function accepts INTEGER n as parameter.
 */

// #include <vector>

void extraLongFactorials(int & _n) {
    using namespace std;
    auto digits = vector<int>({1});
    for(auto num = 2; num <= _n; ++num){
        for(auto it = begin(digits); it != end(digits);
            ++it
        ){
            *it *= num;
        }      
        for(auto i = 0; i < digits.size(); ++i){
            if(digits.at(i) < 10){
                continue;
            }
            if(i == digits.size() - 1){
                digits.emplace_back(0);
            }
            digits.at(i + 1) += digits.at(i) / 10;
            digits.at(i) %= 10; 
        }
    }
    for(auto it = crbegin(digits); it != crend(digits);
        ++it
    ){
        cout << *it;
    }
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    extraLongFactorials(n);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
