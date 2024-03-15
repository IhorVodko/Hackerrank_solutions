// problem : https://www.hackerrank.com/challenges/minimum-absolute-difference-in-an-array/problem?isFullScreen=true


#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'minimumAbsoluteDifference' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */
 
// #include <limits>
// #include <vector>

// #include <cstdlib>

int minimumAbsoluteDifference(std::vector<int> _nums) {
    std::sort(_nums.begin(), _nums.end());
    int diffMin = std::numeric_limits<int>::max();
    int tempMin = std::numeric_limits<int>::max();
    for(auto it1 = _nums.cbegin(), it2 = it1 + 1;
        it2 != _nums.cend();
        ++it1, ++it2
    ){
        tempMin = std::abs(*it1 - *it2);
        if(tempMin == 0){
            return 0;
        }
        if(tempMin < diffMin){
            diffMin = tempMin;
        }
    }
    return diffMin;
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

    int result = minimumAbsoluteDifference(arr);

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
