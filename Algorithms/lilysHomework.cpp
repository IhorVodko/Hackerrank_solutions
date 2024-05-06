// problem: https://www.hackerrank.com/challenges/lilys-homework/problem?isFullScreen=true


#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'lilysHomework' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

// #include <algorithm>
// #include <vector>

namespace Homework{

template<typename _Iterator_t>
size_t countSwaps(
    _Iterator_t && _numSorted,
    std::vector<int> const & _nums
){
    size_t swaps = 0;
    auto nums = _nums;
    for(auto num = std::begin(nums); num != std::end(nums);
        ++num, ++_numSorted
    ){
        if(*num == *_numSorted){
            continue;
        }
        std::swap(*num, *std::find(num + 1, std::end(nums), *_numSorted));
        ++swaps;
    }
    return swaps;
}

} // Homework

int lilysHomework(
    std::vector<int> const & _nums
){
    auto numsSorted = _nums;
    std::sort(std::begin(numsSorted), std::end(numsSorted));
    return static_cast<int>(
        std::min(Homework::countSwaps(std::cbegin(numsSorted), _nums),
            Homework::countSwaps(std::crbegin(numsSorted), _nums)));
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

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

    int result = lilysHomework(arr);

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
