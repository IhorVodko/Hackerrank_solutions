// problem: https://www.hackerrank.com/challenges/almost-sorted/problem?isFullScreen=true


#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'almostSorted' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

// #include <algorithm>
// #include <iostream>
// #include <vector>

void almostSorted(std::vector<int> & _nums){
    auto const & sz = _nums.size();
    auto indxs = std::vector<size_t>();
    indxs.reserve(sz);
    auto numsSorted = _nums;
    sort(std::begin(numsSorted), std::end(numsSorted));
    for(size_t a = 0; a < sz; ++a){
        if(_nums.at(a) == numsSorted.at(a)){
            continue;
        }
        indxs.emplace_back(a);
    }
    for(auto a1 = crbegin(indxs), a2 = --crend(indxs);a1 <= a2;
        ++a1, --a2
    ){
        if(_nums.at(*a1) == numsSorted.at(*a2)){
            continue;
        }
        std::cout << "no\n";
        return;
    }
    std::cout << "yes" << '\n';
    if(indxs.empty()){
        return;
    }
    std::cout << (indxs.size() <= 2 ? "swap " : "reverse ") << 
        ++indxs.front() << " " << ++indxs.back() << '\n'; 
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

    almostSorted(arr);

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
