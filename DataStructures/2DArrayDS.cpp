// problem: https://www.hackerrank.com/challenges/2d-array/problem?isFullScreen=true


#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'hourglassSum' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY arr as parameter.
 */

// #include <algorithm>
// #include <limits>
// #include <vector>

int hourglassSum(std::vector<std::vector<int>> const & _nums){
    using namespace std;
    auto tempSum = std::numeric_limits<int>::min();
    auto maxSum = std::numeric_limits<int>::min();
    for(auto line = 0; line != _nums.size() - 2; ++line){
        for(auto col = 0; col != _nums.size() - 2; ++col){
            tempSum =   _nums.at(line).at(col) + 
                        _nums.at(line).at(col + 1) +
                        _nums.at(line).at(col + 2) + 
                        _nums.at(line + 1).at(col + 1) +
                        _nums.at(line + 2).at(col) +
                        _nums.at(line + 2).at(col + 1) +
                        _nums.at(line + 2).at(col + 2)
            ;
            maxSum = max(maxSum, tempSum);
        }
    }
    return maxSum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> arr(6);

    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        string arr_row_temp_temp;
        getline(cin, arr_row_temp_temp);

        vector<string> arr_row_temp = split(rtrim(arr_row_temp_temp));

        for (int j = 0; j < 6; j++) {
            int arr_row_item = stoi(arr_row_temp[j]);

            arr[i][j] = arr_row_item;
        }
    }

    int result = hourglassSum(arr);

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
