// problem: https://www.hackerrank.com/challenges/connected-cell-in-a-grid/problem?isFullScreen=true


#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'connectedCell' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY matrix as parameter.
 */

// #include <algorithm>
// #include <cassert>
// #include <vector>

int connectedCell(std::vector<std::vector<int>> & _m){
    using namespace std;
    assert(_m.size() > 0 && _m.front().size() > 0);
    static const auto connected = vector<pair<int, int>>(
        {{0, 0},{-1, 0},{-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1},
        {-1, -1}});
    auto const rows = static_cast<int>(_m.size());
    auto const cols = static_cast<int>(_m.front().size());
    auto inRegion = vector<pair<int, int>>();
    inRegion.reserve(82);
    auto maxRegion = 0;
    auto rowNum = 0;
    for_each(begin(_m), end(_m), [&](auto & _row){
        auto _colNum = 0;
        for_each(begin(_row), end(_row), [&](auto & _cell){
            if(_cell != 1){
                ++_colNum;
                return; 
            }
            auto currentRegion = 0;
            inRegion.emplace_back(rowNum, _colNum);
            for(size_t current = 0; current != inRegion.size(); ++current){
                for_each(begin(connected), end(connected), [&](auto & _loc){
                    auto    rowNew = inRegion.at(current).first + _loc.first,
                            colNew = inRegion.at(current).second + _loc.second;
                    if( !(0 <= rowNew && rowNew < rows && 0 <= colNew &&
                        colNew < cols && _m.at(rowNew).at(colNew) == 1)
                    ){
                        return;   
                    }
                    ++_m.at(rowNew).at(colNew);
                    ++currentRegion;
                    inRegion.emplace_back(rowNew, colNew);  
                });
            }
            maxRegion = max(currentRegion, maxRegion);
            inRegion.clear();
            ++_colNum;
        });
        ++rowNum;
    });
    return maxRegion;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string m_temp;
    getline(cin, m_temp);

    int m = stoi(ltrim(rtrim(m_temp)));

    vector<vector<int>> matrix(n);

    for (int i = 0; i < n; i++) {
        matrix[i].resize(m);

        string matrix_row_temp_temp;
        getline(cin, matrix_row_temp_temp);

        vector<string> matrix_row_temp = split(rtrim(matrix_row_temp_temp));

        for (int j = 0; j < m; j++) {
            int matrix_row_item = stoi(matrix_row_temp[j]);

            matrix[i][j] = matrix_row_item;
        }
    }

    int result = connectedCell(matrix);

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
