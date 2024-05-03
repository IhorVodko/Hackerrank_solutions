// problem: https://www.hackerrank.com/challenges/count-luck/problem?isFullScreen=true


#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'countLuck' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING_ARRAY matrix
 *  2. INTEGER k
 */

// #include <vector>
// #include <utility>
// #include <iterator>

namespace Forest{  

using location_t = std::pair<size_t, size_t>;
using locations_t = std::vector<location_t>;
using path_t = locations_t;
using paths_t = std::vector<path_t>;

static constexpr char START = 'M'; 
static constexpr char DESTINATION = '*'; 
static constexpr char BLOCKED = 'X';
static constexpr std::array<std::pair<int, int>, 4> directions = {
    std::make_pair(-1, 0), std::make_pair(0, 1),
    std::make_pair(1, 0), std::make_pair(0, -1)};

location_t findLocation(
    std::vector<std::string>  const &,
    char const &
);

paths_t collectPathes(
    std::vector<std::string> &,
    location_t const &
);

size_t countHints(
    paths_t const & _pathes, 
    location_t const & _start
);

std::string countLuck(
    std::vector<std::string> & _forest,
    int const & _hints
){
    auto const start = findLocation(_forest, START);
    auto pathes = collectPathes(_forest, start);
    auto hintsUsed = countHints(pathes, start);
    std::cout << _hints << " " << hintsUsed << '\n';
    return _hints == static_cast<int>(hintsUsed) ? "Impressed" : "Oops!";
}

inline location_t findLocation(
    std::vector<std::string>  const & _forest,
    char const & _value
){
    auto const & szRows = _forest.size();
    auto const & szCols = _forest.front().size();
    auto destination = std::make_pair(std::numeric_limits<size_t>::max(),
        std::numeric_limits<size_t>::max());
    for(size_t r = 0; r < szRows; ++r){
        for(size_t c = 0; c < szCols; ++c){
            if(_forest.at(r).at(c) != _value){
                continue;;
            }
            return {r, c};
        }
    }
    return destination; 
}

paths_t collectPathes(
    std::vector<std::string> & _forest,
    location_t const & _start
){
    auto const destination = findLocation(_forest, DESTINATION);
    _forest.at(_start.first).at(_start.second) = BLOCKED;
    auto nextLocationOptions = locations_t();
    nextLocationOptions.reserve(directions.size());
    size_t rowNext = std::numeric_limits<size_t>::max();
    size_t colNext = rowNext;
    auto pathes = paths_t();
    pathes.emplace_back(path_t({_start}));
    auto const & szRows = _forest.size();
    auto arrived = false;
    auto const & szCols = _forest.front().size();
    for(size_t pathIndx = 0, locationIndx = 0; pathIndx < pathes.size()
        && !arrived;
    ){
        auto & path = pathes.at(pathIndx);
        auto & location = path.at(locationIndx);
        for(auto const & direction : directions){
            rowNext = location.first + direction.first;
            colNext = location.second + direction.second;
            if( rowNext < 0 || szRows <= rowNext ||
                colNext < 0 || szCols <= colNext ||
                _forest.at(rowNext).at(colNext) == BLOCKED
            ){
                continue;
            }
            _forest.at(rowNext).at(colNext) = BLOCKED;
            nextLocationOptions.emplace_back(rowNext, colNext);
        }
        if(nextLocationOptions.size() == 1){
            path.emplace_back(nextLocationOptions.back());
            ++locationIndx;
            if(nextLocationOptions.back() == destination){
                arrived = true;
            }
            nextLocationOptions.clear();
            continue;
        }
        for(auto const & nextLocationOption: nextLocationOptions){
            pathes.emplace_back(path_t({location}));
            pathes.back().emplace_back(nextLocationOption);
            if(nextLocationOption == destination){
                arrived = true;
            }
        }
        ++pathIndx;
        locationIndx = 1;
        nextLocationOptions.clear();
    }
    return pathes;
}

inline size_t countHints(
    paths_t const & _pathes, 
    location_t const & _start
){
    size_t hintsUsed = 0;
    for(auto path = std::rbegin(_pathes), pathPrev = path + 1;
        pathPrev != rend(_pathes);
        path = pathPrev,  pathPrev = path + 1
    ){
        ++hintsUsed;
        if(path->front() == _start){
            break;
        }
        while(path->front() != pathPrev->back()){
            ++pathPrev;
        }
    }
    return hintsUsed;
}

} // namespace Forest

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

        int n = stoi(first_multiple_input[0]);

        int m = stoi(first_multiple_input[1]);

        vector<string> matrix(n);

        for (int i = 0; i < n; i++) {
            string matrix_item;
            getline(cin, matrix_item);

            matrix[i] = matrix_item;
        }

        string k_temp;
        getline(cin, k_temp);

        int k = stoi(ltrim(rtrim(k_temp)));

        string result = Forest::countLuck(matrix, k);

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
