// problem: https://www.hackerrank.com/challenges/knightl-on-chessboard/problem?isFullScreen=true


#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'knightlOnAChessboard' function below.
 *
 * The function is expected to return a 2D_INTEGER_ARRAY.
 * The function accepts INTEGER n as parameter.
 */

// #include <algorithm>
// #include <vector>
// #include <utility>

template<typename T>
using vec = std::vector<T>;
using pr = std::pair<int, int>;


bool arrived(
    vec<vec<bool>> &  _board,
    vec<pr> & _level,
    int const _row,
    int const _col,
    int const & _border,
    pr const & _finish
    
){
    if( 0 <= _row && _row < _border && 0 <= _col && _col < _border &&
        _board.at(_row).at(_col)
    ){
        _level.emplace_back(_row, _col);
        _board.at(_row).at(_col) = false;
    }
    return !_level.empty() && _level.back() == _finish;
}

std::vector<std::vector<int>> knightlOnAChessboard(
    int const & _border
){
    auto border = static_cast<size_t>(_border);
    auto moveInstructions = vec<vec<pr>>();
    for(size_t i1 = 1; i1 < border; ++i1){
        moveInstructions.emplace_back();
        for(size_t i2 = 1; i2 < border; ++i2){
            moveInstructions.back().emplace_back(i1, i2);
        }
    }
    auto board = vec<vec<bool>>(border, vec<bool>(border, true));
    auto result = vec<vec<int>>();
    auto tree = vec<vec<pr>>();
    auto finish = pr(border - 1, border - 1);
    auto ones = vec<int>({1, 1, -1, -1, 1});
    auto hasArrived = false;
    for(auto const & moveInstructionsSameRow: moveInstructions){
        result.emplace_back();
        for(auto const & move: moveInstructionsSameRow){
            board.at(0).at(0) = false;
            tree.emplace_back();
            tree.back().emplace_back(0,0);
            hasArrived = false;
            auto const & [r1, c1] = move;
            for(size_t i = 0; i < tree.size(); ++i){
                tree.emplace_back();
                for(auto const & cell: tree.at(i)){
                    auto const & [r2, c2] = cell;
                    for(size_t i = 0; i + 1 < ones.size(); ++i){
                        hasArrived = hasArrived || 
                            arrived(board, tree.back(), 
                                r2 + r1 * ones.at(i),
                                    c2 + c1 * ones.at(i + 1), border,
                                    finish) || 
                            arrived(board, tree.back(), 
                                r2 + c1 * ones.at(i), 
                                c2 + r1 * ones.at(i + 1), border, 
                                finish);
                    }
                }
                if(hasArrived){
                    break;
                }
                if(tree.back().empty()){
                    tree.pop_back();
                }
            }
            result.back().emplace_back(hasArrived ? tree.size() - 1 : -1);
            tree.clear();
            hasArrived = false;
            for(auto & row: board){
                std::fill(std::begin(row), std::end(row), true);
            }
        }
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<vector<int>> result = knightlOnAChessboard(n);

    for (size_t i = 0; i < result.size(); i++) {
        for (size_t j = 0; j < result[i].size(); j++) {
            fout << result[i][j];

            if (j != result[i].size() - 1) {
                fout << " ";
            }
        }

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
