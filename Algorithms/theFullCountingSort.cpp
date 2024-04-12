// problem: https://www.hackerrank.com/challenges/countingsort4/problem?isFullScreen=true


#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'countSort' function below.
 *
 * The function accepts 2D_STRING_ARRAY arr as parameter.
 */
 
// #include <iterator>
// #include <map>
// #include <string>
// #include <vector>
// #include <utility>

void countSort(std::vector<std::vector<std::string>> & _arr){
    using namespace std;
    auto middle = cbegin(_arr);
    advance(middle, _arr.size() / 2);
    auto mapCount = map<int, string>();
    for(auto it = begin(_arr); it != end(_arr); ++it){
        if(it < middle){
            mapCount[stoi((*it).at(0))] += "- ";
        }else{
            mapCount[stoi((*it).at(0))] += std::move((*it).at(1)) + " ";
        }
    }
    (*rbegin(mapCount)).second.pop_back();
    for(auto const & numAndStrs : mapCount){
        cout << numAndStrs.second;
    }
    cout << endl;
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<vector<string>> arr(n);

    for (int i = 0; i < n; i++) {
        arr[i].resize(2);

        string arr_row_temp_temp;
        getline(cin, arr_row_temp_temp);

        vector<string> arr_row_temp = split(rtrim(arr_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            string arr_row_item = arr_row_temp[j];

            arr[i][j] = arr_row_item;
        }
    }

    countSort(arr);

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
