// problem: https://www.hackerrank.com/challenges/two-pluses/problem?isFullScreen=true


#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'twoPluses' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING_ARRAY grid as parameter.
 */

// #include <algorithm>
// #include <vector>
// #include <string>
// #include <utility>

class Plus;
int findMaxVal(std::vector<std::vector<::Plus>> const &);
std::vector<std::vector<::Plus>> findAllPluses(std::vector<std::string>);


int twoPluses(std::vector<std::string> _mtrx){
    return findMaxVal(findAllPluses(_mtrx));
}

class Plus{
public:
    explicit Plus() = default;
    Plus(Plus const &) = default;
    Plus(Plus  &&) = default;
    Plus & operator=(Plus const &) = default;
    Plus & operator=(Plus  &&) = default;
    ~Plus() = default;
    
    void insert(
        size_t const & _row,
        size_t const & _col
    ){
        rowCol.emplace_back(_row, _col);
    }
    auto & get() const noexcept{
        return rowCol;
    }

private:
    std::vector<std::pair<size_t, size_t>> rowCol;
};


int findMaxVal(std::vector<std::vector<::Plus>> const & _Pluses){
    size_t maxVal = std::numeric_limits<size_t>::min();
    for(auto PlusesIt1 = cbegin(_Pluses); PlusesIt1 != cend(_Pluses);
        ++PlusesIt1
    ){
        for(auto PlusesIt2 = PlusesIt1; PlusesIt2 != cend(_Pluses);
            ++PlusesIt2
        ){
            for(auto PlusIt1 = cbegin(*PlusesIt1);
                PlusIt1 != cend(*PlusesIt1); ++PlusIt1
            ){
                for(auto PlusIt2 = cbegin(*PlusesIt2);
                    PlusIt2 != cend(*PlusesIt2); ++PlusIt2
                ){
                    for(auto const & rowCol : (*PlusIt1).get()){
                        if( find(cbegin((*PlusIt2).get()),
                            cend((*PlusIt2).get()),
                            rowCol) != cend((*PlusIt2).get())
                        ){
                            break;
                        }
                        if(rowCol == (*PlusIt1).get().back()){
                            maxVal = std::max(maxVal,
                                ((*PlusIt1).get().size() - 1) *
                                    ((*PlusIt2).get().size() - 1));
                        }
                    }
                }
            }
        }
    }
    return static_cast<int>(maxVal); 
}

std::vector<std::vector<::Plus>> findAllPluses(
    std::vector<std::string> _mtrx
){
    static constexpr auto Bad = 'B';
    auto const rowSz = _mtrx.size();
    auto const colSz = _mtrx.front().size();
    auto Pluses = std::vector<std::vector<::Plus>>();
    auto const PlusSzMax = std::min(rowSz, colSz);
    auto isValidPlus = true;
    size_t colMiddle = std::numeric_limits<size_t>::max();
    for(size_t PlusSz = 1; PlusSz <= PlusSzMax; PlusSz += 2){
        Pluses.emplace_back(std::vector<::Plus>());
        auto const margin = PlusSz / 2;
        for(auto row = margin; row != rowSz - margin; ++row){
            for(size_t col = 0; col != colSz - PlusSz + 1; ++col){
                if(_mtrx.at(row).at(col) == Bad){
                   continue;
                }
                isValidPlus = true;
                Pluses.back().emplace_back(::Plus());
                for(size_t colHLimit = 1, colH = col; colHLimit <= PlusSz;
                    ++colHLimit, ++colH
                ){
                    if(_mtrx.at(row).at(colH) == Bad){
                        isValidPlus = false;
                        break;
                    }
                    Pluses.back().back().insert(row, colH);
                }
                if(!isValidPlus){
                    Pluses.back().pop_back();
                    continue;
                }
                colMiddle = col + margin;
                for(size_t rowVlimit = 1, rowV = row - margin;
                    rowVlimit <= PlusSz; ++rowVlimit, ++rowV
                ){
                    if(_mtrx.at(rowV).at(colMiddle) == Bad){
                        Pluses.back().pop_back();
                        break;
                    }
                    Pluses.back().back().insert(rowV, colMiddle);
                }
            }
        }
        if(Pluses.back().empty()){
            Pluses.pop_back();
        }
    }
    return Pluses;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    vector<string> grid(n);

    for (int i = 0; i < n; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    int result = twoPluses(grid);

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
