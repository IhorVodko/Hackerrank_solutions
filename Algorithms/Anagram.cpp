// problem : https://www.hackerrank.com/challenges/anagram/problem?isFullScreen=true


#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'anagram' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

// #include <algorithm>
// #include <iterator>
// #include <string>

int anagram(std::string _str){
    auto const sz = _str.size();
    if(sz % 2){
        return -1;
    }
    auto const halfSz = sz / 2;
    std::sort(_str.begin(), _str.begin() + halfSz);
    std::sort(_str.begin() + halfSz, _str.end());
    std::string diff(halfSz, '_');
    return std::distance(
            diff.begin()
        ,   std::set_difference(
                _str.cbegin()
            ,   _str.cbegin() + halfSz
            ,   _str.cbegin() + halfSz
            ,   _str.cend()
            ,   diff.begin()
        )
    );
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = anagram(s);

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
