// problem : https://www.hackerrank.com/challenges/beautiful-pairs/problem?isFullScreen=true


#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'beautifulPairs' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY A
 *  2. INTEGER_ARRAY B
 */

// #include <algorithm>
// #include <vector>
// #include <map>

int beautifulPairs(
        std::vector<int> _v1
    ,   std::vector<int> _v2
){
    std::map<int, size_t> map1;
    std::map<int, size_t> map2;
    for(auto const & x : _v1){
        ++map1[x];
    }
    for(auto const & x : _v2){
        ++map2[x];
    }
    size_t pairs = 0;
    bool hasExtraPair = false;
    for(auto const & pair : map1){
        if(map2.find(pair.first) != map2.cend()){
            pairs += std::min(pair.second, map2[pair.first]);
        }else{
            hasExtraPair = true;
        }
    }
    return hasExtraPair ? ++pairs : --pairs;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string A_temp_temp;
    getline(cin, A_temp_temp);

    vector<string> A_temp = split(rtrim(A_temp_temp));

    vector<int> A(n);

    for (int i = 0; i < n; i++) {
        int A_item = stoi(A_temp[i]);

        A[i] = A_item;
    }

    string B_temp_temp;
    getline(cin, B_temp_temp);

    vector<string> B_temp = split(rtrim(B_temp_temp));

    vector<int> B(n);

    for (int i = 0; i < n; i++) {
        int B_item = stoi(B_temp[i]);

        B[i] = B_item;
    }

    int result = beautifulPairs(A, B);

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
