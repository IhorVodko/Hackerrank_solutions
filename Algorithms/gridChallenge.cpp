//  problem : https://www.hackerrank.com/challenges/grid-challenge/problem?isFullScreen=true


#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'gridChallenge' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING_ARRAY grid as parameter.
 */

// #include <algorithm>
// #include <string>
// #include <vector>

std::string gridChallenge(std::vector<std::string> _grid){
    for(auto & line : _grid){
        std::sort(line.begin(), line.end());
    }
    size_t i = 0;
    size_t const sz = _grid.front().size();
    for(auto it1 = _grid.begin(), it2 = it1 + 1;
        it2 != _grid.end();
        it1 = it2, ++it2, i = 0
    ){
        while(i < sz){
            if((*it1)[i] > (*it2)[i]){
                return "NO";
            }
            ++i;
        }
    }
    return "YES";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        vector<string> grid(n);

        for (int i = 0; i < n; i++) {
            string grid_item;
            getline(cin, grid_item);

            grid[i] = grid_item;
        }

        string result = gridChallenge(grid);

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
