#Proble: https://www.hackerrank.com/challenges/repeated-string/problem

#include <bits/stdc++.h>


using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'repeatedString' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. LONG_INTEGER n
 */

long repeatedString(const string& s, long n) 
{
    const char chr = 'a';
    long countaInStr, strSize, countaInFullStr;
    countaInStr = count(s.begin(), s.end(), chr);
    strSize = s.size();
    countaInFullStr =  (n / strSize) * countaInStr;
    string subStr = s.substr(0, n % strSize);
    long countaInResStr = count(subStr.begin(), subStr.end(), chr);
    return (countaInFullStr + countaInResStr);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string n_temp;
    getline(cin, n_temp);

    long n = stol(ltrim(rtrim(n_temp)));

    long result = repeatedString(s, n);

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
