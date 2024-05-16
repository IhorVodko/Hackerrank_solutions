// problem: https://www.hackerrank.com/challenges/gridland-metro/problem?isFullScreen=true


#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'gridlandMetro' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER m
 *  3. INTEGER k
 *  4. 2D_INTEGER_ARRAY track
 */

// #include <algorithm>
// #include <vector>

size_t gridlandMetro(
    size_t const & _rows,
    size_t const & _columns,
    size_t const & _tracksTotalNum,
    std::vector<vector<size_t>> & _tracks
){
    if(_tracks.empty()){
        return _rows * _columns;
    }else if(_tracks.size() == 1){
        return _rows * _columns - (_tracks.front().at(2) -
            _tracks.front().at(1) + 1);
    }
    std::sort(std::begin(_tracks), std::end(_tracks));
    size_t lamps = _rows * _columns;
    for(auto current = std::begin(_tracks), next = current + 1;
        next < std::end(_tracks); ++current, ++next
    ){
        if((*current).at(0) == (*next).at(0)){
            if((*current).at(2) + 1 >= (*next).at(1)){
                (*next).at(1) = (*current).at(1);
                if((*current).at(2) > (*next).at(2)){
                    (*next).at(2) = (*current).at(2);
                }
            }else{
                lamps -= (*current).at(2) - (*current).at(1) + 1;
            }
        }else{
            lamps -= (*current).at(2) - (*current).at(1) + 1;
        }
        if(next + 1 == std::end(_tracks)){
            lamps -= (*next).at(2) - (*next).at(1) + 1;
        }
    }
    return lamps;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    int k = stoi(first_multiple_input[2]);

    vector<vector<size_t>> track(k);

    for (int i = 0; i < k; i++) {
        track[i].resize(3);

        string track_row_temp_temp;
        getline(cin, track_row_temp_temp);

        vector<string> track_row_temp = split(rtrim(track_row_temp_temp));

        for (int j = 0; j < 3; j++) {
            size_t track_row_item = stoi(track_row_temp[j]);

            track[i][j] = track_row_item;
        }
    }

    size_t result = gridlandMetro(n, m, k, track);

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
