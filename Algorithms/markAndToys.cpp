// problem : https://www.hackerrank.com/challenges/mark-and-toys/problem?isFullScreen=true


#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'maximumToys' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY prices
 *  2. INTEGER k
 */

// #include <algorithm>
// #include <vector>

int maximumToys(
        std::vector<int> _prices
    ,   int _budget
){
    std::sort(_prices.begin(), _prices.end());
    int toys = 0;
    for(auto const & price : _prices){
        if(_budget < price){
            return toys; 
        }
        _budget -= price;
        ++toys;
    }
    return toys;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string prices_temp_temp;
    getline(cin, prices_temp_temp);

    vector<string> prices_temp = split(rtrim(prices_temp_temp));

    vector<int> prices(n);

    for (int i = 0; i < n; i++) {
        int prices_item = stoi(prices_temp[i]);

        prices[i] = prices_item;
    }

    int result = maximumToys(prices, k);

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
