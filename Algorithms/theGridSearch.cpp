// problem: https://www.hackerrank.com/challenges/the-grid-search/problem?isFullScreen=true


#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'gridSearch' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING_ARRAY G
 *  2. STRING_ARRAY P
 */

// #include <algorithm>
// #include <numeric>
// #include <string>
// #include <vector>
  
inline std::vector<size_t> fndMatches(
    std::string const & _str,
    std::string const & _pttrn
){
    using namespace std;
    auto idxMatch = _str.find(_pttrn);
    auto matches = vector<size_t>();
    while(idxMatch != string::npos){
        matches.emplace_back(idxMatch++);
        idxMatch = _str.find(_pttrn, idxMatch);
    }
    return matches;
}
  
std::string gridSearch(
    std::vector<std::string> const & _mtrx,
    std::vector<std::string> const & _pttrn
){
    using namespace std;
    auto matchesIntersection = vector<size_t>(_mtrx.front().size(),
        numeric_limits<size_t>::max());
    for(auto rowM = cbegin(_mtrx); rowM != cend(_mtrx); ++rowM){
        auto matches = ::fndMatches(*rowM, _pttrn.front());
        if(matches.empty()){
            continue;
        }
        copy(cbegin(matches), cend(matches), begin(matchesIntersection));
        for(auto rowMCopy = rowM, rowP = cbegin(_pttrn); 
             rowMCopy != cend(_mtrx) && rowP != cend(_pttrn);
             ++rowMCopy, ++rowP
        ){
            auto matchesNext = ::fndMatches(*rowMCopy, *rowP);
            auto itEnd = set_intersection(
                cbegin(matchesIntersection), cend(matchesIntersection),
                cbegin(matchesNext), cend(matchesNext), 
                begin(matchesIntersection));
            if(itEnd == begin(matchesIntersection)){
                break;
            }
            if(rowP == --cend(_pttrn)){
                return "YES";
            }
        }
    }
    return "NO";
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

        int R = stoi(first_multiple_input[0]);

        int C = stoi(first_multiple_input[1]);

        vector<string> G(R);

        for (int i = 0; i < R; i++) {
            string G_item;
            getline(cin, G_item);

            G[i] = G_item;
        }

        string second_multiple_input_temp;
        getline(cin, second_multiple_input_temp);

        vector<string> second_multiple_input = split(rtrim(second_multiple_input_temp));

        int r = stoi(second_multiple_input[0]);

        int c = stoi(second_multiple_input[1]);

        vector<string> P(r);

        for (int i = 0; i < r; i++) {
            string P_item;
            getline(cin, P_item);

            P[i] = P_item;
        }

        string result = gridSearch(G, P);

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
