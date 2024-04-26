// problem: https://www.hackerrank.com/challenges/sherlock-and-anagrams/problem?isFullScreen=true


#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'sherlockAndAnagrams' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

// #include <algorithm>
// #include <string>
// #include <unordered_map>
// #include <utility>

template<>
class std::hash<vector<size_t>>{
public:
    using Key_t = vector<size_t>;
    size_t operator()(Key_t const & _key) const{
        std::size_t seed = _key.size();
        for(auto const & i: _key){
            seed ^= i + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        }
        return seed;
    }
};

int sherlockAndAnagrams(std::string const & _str){
    auto const strSz = _str.size();
    int anagramsCount = 0;
    auto chars = vector<size_t>(26, 0);
    auto subStrs = std::unordered_map<decltype(chars), size_t>();
    for(size_t sz = 1; sz < strSz; ++sz){
        for(auto start1 = std::begin(_str), end1 = start1 + sz;
            end1 <= std::end(_str); ++start1, ++end1
        ){
            for(auto chr = start1; chr < end1; ++chr){
                ++chars.at(*chr - 'a');
            }
            subStrs[chars]++;
            std::fill(std::begin(chars), std::end(chars), 0);
        }
    }
    for(auto const & [subStr, count]: subStrs){
        anagramsCount += (count * (count - 1) / 2);
    }
    return static_cast<int>(anagramsCount);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = sherlockAndAnagrams(s);

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

