// problem : https://www.hackerrank.com/challenges/two-strings/problem?isFullScreen=true


#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'twoStrings' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING s1
 *  2. STRING s2
 */

// #include <algorithm>
// #include <string>

std::string twoStrings(
        std::string _s1
    ,   std::string _s2
){
    std::sort(_s1.begin(), _s1.end());
    std::sort(_s2.begin(), _s2.end());
    for(auto it1 = _s1.cbegin(), it2 = _s2.cbegin();
        it1 != _s1.cend() && it2 != _s2.cend();
    ){
        if(*it1 == *it2){
            return "YES";
        }else if(*it1 < *it2){
            ++it1;
        }else{
            ++it2;
        }
    }
    return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        string result = twoStrings(s1, s2);

        fout << result << "\n";
    }

    fout.close();

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
