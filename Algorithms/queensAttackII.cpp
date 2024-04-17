// problem: https://www.hackerrank.com/challenges/queens-attack-2/problem?isFullScreen=true


#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'queensAttack' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER k
 *  3. INTEGER r_q
 *  4. INTEGER c_q
 *  5. 2D_INTEGER_ARRAY obstacles
 */

// #include <algorithm>
// #include <vector>

int queensAttack(
    int const & _n, 
    int const & _k,
    int const & _rQ,
    int const & _cQ,
    std::vector<std::vector<int>> & _obstacles
){
    using namespace std;
    auto leftMoves = _cQ - 1;
    auto rightMoves = _n - _cQ;
    auto upMoves = _rQ - 1;
    auto downMoves = _n - _rQ;
    auto toUpperLeftMoves = min(_rQ - 1, _cQ - 1);
    auto toLowerRightMoves = min(_n - _rQ, _n - _cQ);
    auto toUpperRightMoves = min(_rQ - 1, _n - _cQ);
    auto toLowerLeftMoves = min(_n - _rQ, _cQ - 1);
    auto diff = _rQ - _cQ;
    auto sum = _rQ + _cQ;
    for(auto const & rc : _obstacles){
        if(rc.at(0) == _rQ){
            if(rc.at(1) < _cQ){
                leftMoves = min(leftMoves, _cQ - rc.at(1) - 1);
            }else{
                 rightMoves = min(rightMoves, rc.at(1) - _cQ - 1);
            }
        }else if(rc.at(1) == _cQ){
            if(rc.at(0) < _rQ){
                upMoves = min(upMoves, _rQ - rc.at(0) - 1);
            }else{
                downMoves = min(downMoves, rc.at(0) - _rQ - 1);
            }
        }else if(rc.at(0) - rc.at(1) == diff){
            if(rc.at(0) < _rQ){
                toUpperLeftMoves = min(toUpperLeftMoves, _rQ - rc.at(0)
                    - 1);
            }else{
                toLowerRightMoves = min(toLowerRightMoves, rc.at(0) - _rQ
                    - 1);
            }
        }else if(rc.at(0) + rc.at(1) == sum){
            if(rc.at(0) < _rQ){
                toUpperRightMoves = min(toUpperRightMoves, _rQ - rc.at(0)
                    - 1);
            }else{
                toLowerLeftMoves = min(toLowerLeftMoves, rc.at(0) - _rQ - 1);
            }
        }
    }
    return leftMoves + rightMoves + upMoves + downMoves + toUpperLeftMoves
        + toLowerRightMoves + toUpperRightMoves + toLowerLeftMoves;
}
 
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string second_multiple_input_temp;
    getline(cin, second_multiple_input_temp);

    vector<string> second_multiple_input = split(rtrim(second_multiple_input_temp));

    int r_q = stoi(second_multiple_input[0]);

    int c_q = stoi(second_multiple_input[1]);

    vector<vector<int>> obstacles(k);

    for (int i = 0; i < k; i++) {
        obstacles[i].resize(2);

        string obstacles_row_temp_temp;
        getline(cin, obstacles_row_temp_temp);

        vector<string> obstacles_row_temp = split(rtrim(obstacles_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int obstacles_row_item = stoi(obstacles_row_temp[j]);

            obstacles[i][j] = obstacles_row_item;
        }
    }

    int result = queensAttack(n, k, r_q, c_q, obstacles);

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
