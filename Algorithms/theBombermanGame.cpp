// problem: https://www.hackerrank.com/challenges/bomber-man/problem?isFullScreen=true


#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'bomberMan' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. STRING_ARRAY grid
 */

#include <string>
#include <vector>

std::vector<std::string> bomberMan(
    int _sec,
    std::vector<std::string> & _mtrx
){
    if(_sec == 1){
        return _mtrx;
    }
    _sec %= 4;
    if(_sec == 0){
        _sec = 4;
    }else if(_sec == 1){
        _sec = 5;
    }
    auto secPassed = 1;
    auto const rowSz = _mtrx.size();
    auto const colSz = _mtrx.front().size();
    auto toDetonate = 'O';
    auto toPlant = 'I';
    auto temp = 'X';
    while(secPassed++ != _sec){
        if(secPassed % 2 == 0){
            for(auto & row: _mtrx){
                for(auto & col: row){
                    if(col == '.'){
                        col = toPlant;
                    }
                }
            }
            temp = toPlant;
            toPlant = toDetonate;
            continue;
        }
        for(auto row = 0; row != rowSz; ++row){
            for(auto col = 0; col != colSz; ++col){
                if(_mtrx.at(row).at(col) != toDetonate){
                    continue;
                }
                _mtrx.at(row).at(col) = '.';
                if( 0 <= row - 1 &&
                    _mtrx.at(row - 1).at(col) != toDetonate
                ){
                    _mtrx.at(row - 1).at(col) = '.';
                }
                if( row + 1 != rowSz &&
                    _mtrx.at(row + 1).at(col) != toDetonate
                ){
                    _mtrx.at(row + 1).at(col) = '.';
                }
                if( 0 <= col - 1 &&
                    _mtrx.at(row).at(col - 1) != toDetonate
                ){
                    _mtrx.at(row).at(col - 1) = '.';
                }
                if( col + 1 != colSz &&
                    _mtrx.at(row).at(col + 1) != toDetonate
                ){
                        _mtrx.at(row).at(col + 1) = '.';
                }
            }
        }
        toDetonate = temp;
    }
    for(auto & row: _mtrx){
        for(auto & col: row){
            if(col != '.'){
                col = 'O';
            }
        }
    }
    return _mtrx;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int r = stoi(first_multiple_input[0]);

    int c = stoi(first_multiple_input[1]);

    int n = stoi(first_multiple_input[2]);

    vector<string> grid(r);

    for (int i = 0; i < r; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    vector<string> result = bomberMan(n, grid);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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
