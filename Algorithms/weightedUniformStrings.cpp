// problem : https://www.hackerrank.com/challenges/weighted-uniform-string/problem?isFullScreen=true


#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'weightedUniformStrings' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. INTEGER_ARRAY queries
 */

// #include <algorithm>
// #include <unordered_map>
// #include <set>

vector<std::string> weightedUniformStrings(
        std::string const & _str
    ,   std::vector<int> const & _qrs
) {
    std::unordered_map<char, int> chrCounts;
    int newChrCount{0};
    for(
            auto first = _str.cbegin()
        ,   last = first;
            last != _str.cend();
            first = last
    ){
        do{
            ++newChrCount;
            ++last;
        } while(*first == *last && last != _str.cend());
        chrCounts[*first] = std::max(chrCounts[*first], newChrCount);
        newChrCount = 0;
    }
    std::set<int> wghts;
    int wght{0};
    for(auto & el : chrCounts) {
        wght = el.first - 'a' + 1;
        do{
            wghts.insert(wght * el.second);
            --el.second;
        } while(el.second > 0);
    }
    std::vector<std::string> result;
    for(auto const & qr : _qrs){
        result.emplace_back(wghts.find(qr) == wghts.cend() ? "No" : "Yes");
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string queries_count_temp;
    getline(cin, queries_count_temp);

    int queries_count = stoi(ltrim(rtrim(queries_count_temp)));

    vector<int> queries(queries_count);

    for (int i = 0; i < queries_count; i++) {
        string queries_item_temp;
        getline(cin, queries_item_temp);

        int queries_item = stoi(ltrim(rtrim(queries_item_temp)));

        queries[i] = queries_item;
    }

    vector<string> result = weightedUniformStrings(s, queries);

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
