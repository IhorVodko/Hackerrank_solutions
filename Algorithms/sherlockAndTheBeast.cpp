// problem: https://www.hackerrank.com/challenges/sherlock-and-the-beast/problem?isFullScreen=true


#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'decentNumber' function below.
 *
 * The function accepts INTEGER n as parameter.
 */

// #include <string>

void decentNumber(int _sz){
    auto sz = static_cast<size_t>(_sz);
    size_t minThrees = 0;
    while(minThrees <= sz){
        if((sz - minThrees) % 3 == 0){
            std::cout << 
                std::string(sz - minThrees, '5') << 
                std::string(minThrees, '3') << '\n'
            ;
            return;
        }
        minThrees += 5;
    }
    std::cout << "-1\n";
}

int main()
{
    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        decentNumber(n);
    }

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
