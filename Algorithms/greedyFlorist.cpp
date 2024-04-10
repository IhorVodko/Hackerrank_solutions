// problem: https://www.hackerrank.com/challenges/greedy-florist/problem?isFullScreen=true


#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the getMinimumCost function below.

// #include <algorithm>
// #include <numeric>
// #include <vector>
// #include <type_traits>

int getMinimumCost(
        int const & _friends
    ,   std::vector<int> & _prices
){
    using namespace std;
    using price_t = remove_reference<decltype(_prices)>::type::value_type;
    if(static_cast<size_t>(_friends) >= _prices.size()){
        return accumulate(begin(_prices), end(_prices), 0);
    }
    sort(begin(_prices), end(_prices), greater<price_t>());
    auto multiplier = 0;
    for(auto i = 1; i != _prices.size(); ++i){
        if(i % _friends == 0){
            ++multiplier;
        }
        _prices.at(i) += _prices.at(i - 1) + _prices.at(i) * multiplier;
    }
    return _prices.back();
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string c_temp_temp;
    getline(cin, c_temp_temp);

    vector<string> c_temp = split_string(c_temp_temp);

    vector<int> c(n);

    for (int i = 0; i < n; i++) {
        int c_item = stoi(c_temp[i]);

        c[i] = c_item;
    }

    int minimumCost = getMinimumCost(k, c);

    fout << minimumCost << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
