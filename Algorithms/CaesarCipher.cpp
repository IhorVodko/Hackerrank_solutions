// problem : https://www.hackerrank.com/challenges/caesar-cipher-1/problem?isFullScreen=true 


#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'caesarCipher' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. INTEGER k
 */

// #include <string>
// #include <cctype>

std::string caesarCipher(
        std::string _str
    ,   int _k
) {
    static constexpr int alphabetLength = 'z' - 'a' + 1;
    char firstChar = 'a';
    for(auto & chr : _str){
        if (isalpha(chr)){
            firstChar = isupper(chr) ? 'A' : 'a';
            chr = static_cast<char>(
                0 + (chr - firstChar + _k) % alphabetLength 
                + firstChar);
        } 
    }
    return _str;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string s;
    getline(cin, s);

    string k_temp;
    getline(cin, k_temp);

    int k = stoi(ltrim(rtrim(k_temp)));

    string result = caesarCipher(s, k);

    fout << result << "\n";

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
