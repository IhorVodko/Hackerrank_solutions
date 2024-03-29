// problem: https://www.hackerrank.com/challenges/insertionsort1/problem?isFullScreen=true


#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'insertionSort1' function below.
 *
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER_ARRAY arr
 */


// #include <vector>

void print(std::vector<int> const & _arr){
    using namespace std;
    for(auto & num : _arr){
        cout << num << " ";
    }
    cout << "\n";
}

void insertionSort1(
        int const & _num
    ,   std::vector<int> & _arr
){
    using namespace std;
    auto num = _arr.back();
    auto itLast = --rend(_arr);
    for(auto it = ++rbegin(_arr); it != rend(_arr); ++it){
        if(*it < num){
            *(it - 1) = num;
            ::print(_arr);
            return;  
        }
        *(it - 1) = *it;
        ::print(_arr);
        if(it == itLast){
            *it = num;
            ::print(_arr);
        }
    }
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    insertionSort1(n, arr);

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
