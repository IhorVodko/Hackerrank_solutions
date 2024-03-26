// problem : https://www.hackerrank.com/challenges/a-chessboard-game-1/problem?isFullScreen=true


#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'chessboardGame' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. INTEGER x
 *  2. INTEGER y
 */

// #include <string>

bool makeMove(
        int _x
    ,   int _y
){
    if( 1 <= _x && _x <= 15 &&
        1 <= _y && _y <= 15
    ){
        return  !makeMove(_x - 2, _y + 1) || 
                !makeMove(_x - 2, _y - 1) || 
                !makeMove(_x + 1, _y - 2) || 
                !makeMove(_x - 1, _y -2)
        ;
    }
    return true;
}

std::string chessboardGame(
        int _x
    ,   int _y
){
    return makeMove(_x, _y) ? "First" : "Second";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int x = stoi(first_multiple_input[0]);

        int y = stoi(first_multiple_input[1]);

        string result = chessboardGame(x, y);

        fout << result << "\n";
    }

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
