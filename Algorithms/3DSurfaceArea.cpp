// problem: https://www.hackerrank.com/challenges/3d-surface-area/problem?isFullScreen=true 


#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'surfaceArea' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY A as parameter.
 */

// #include <algorithm>
// #include <cassert>
// #include <cmath>
// #include <numeric>
// #include <vector>

int surfaceArea(vector<vector<int>> const & _2d){
    // assert(!_2d.empty() && !_2d.front().empty());
    auto const rows = _2d.size();
    auto const cols = _2d.front().size();
    auto bottomAndTopArea = 2 * rows * cols;
    auto frontAndBackArea = 0;
    frontAndBackArea += 
        accumulate(begin(_2d.front()), end(_2d.front()), 0) + 
        accumulate(begin(_2d.back()), end(_2d.back()), 0);
    for(auto i = 0; i < rows - 1; ++i){
        for(auto j = 0; j < cols; ++j){
            frontAndBackArea += abs(_2d.at(i).at(j) -
                _2d.at(i + 1).at(j)); 
        }
    }
    auto leftAndRightArea = 0;
    for_each(begin(_2d), end(_2d), [&](auto const & _row){
        leftAndRightArea += _row.front() + _row.back();});
    for(auto & row: _2d){
        for(auto j = 0; j < cols - 1; ++j){
            leftAndRightArea += abs(row.at(j) -
                row.at(j + 1)); 
        }
    }
    return bottomAndTopArea + frontAndBackArea +
        leftAndRightArea;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int H = stoi(first_multiple_input[0]);

    int W = stoi(first_multiple_input[1]);

    vector<vector<int>> A(H);

    for (int i = 0; i < H; i++) {
        A[i].resize(W);

        string A_row_temp_temp;
        getline(cin, A_row_temp_temp);

        vector<string> A_row_temp = split(rtrim(A_row_temp_temp));

        for (int j = 0; j < W; j++) {
            int A_row_item = stoi(A_row_temp[j]);

            A[i][j] = A_row_item;
        }
    }

    int result = surfaceArea(A);

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
