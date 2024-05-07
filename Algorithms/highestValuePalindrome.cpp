// problem: https://www.hackerrank.com/challenges/richie-rich/problem?isFullScreen=true


#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'highestValuePalindrome' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. INTEGER n
 *  3. INTEGER k
 */

// #include <algorithm>
// #include <string>

std::string highestValuePalindrome(
    std::string & _str,
    int const & _strSz,
    int & _changesAllowed
){
    static constexpr char MAX_DIGIT = '9';
    static constexpr int SHIFT = 10;
    for(auto first = std::begin(_str), last = --std::end(_str);
        first < last; ++first, --last
    ){
        if(*first == *last){
            continue;
        }
        if(_changesAllowed == 0){
            return "-1";
        }
        *first = std::max(*first, *last);
        *last = *first =  *first == MAX_DIGIT ? *first : *first + SHIFT;
        --_changesAllowed;
    }
    for(auto first = std::begin(_str), last = --std::end(_str);
        first < last; ++first, --last
    ){
        if(_changesAllowed == 0){
            for(; first < last; ++first, --last){
                if(*first <= MAX_DIGIT){
                    continue;
                }
                *last = *first -= SHIFT;; 
            }
            return _str;
        }
        if(*first > MAX_DIGIT){
            *last = *first = MAX_DIGIT;
           --_changesAllowed; 
        }else{
            if(_changesAllowed == 1){
                continue;
            }
            if(*first != MAX_DIGIT){
                *last = *first = MAX_DIGIT;
                _changesAllowed -= 2;
            }
        }
    }
    if(_changesAllowed >= 1 && _strSz % 2 == 1){
        _str.at(_strSz / 2) = MAX_DIGIT;
    }
    return _str;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string s;
    getline(cin, s);

    string result = highestValuePalindrome(s, n, k);

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
