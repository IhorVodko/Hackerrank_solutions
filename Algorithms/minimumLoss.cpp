// problem: https://www.hackerrank.com/challenges/minimum-loss/problem?isFullScreen=true


#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'minimumLoss' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts LONG_INTEGER_ARRAY price as parameter.
 */

// #include <algorithm>
// #include <limits>
// #include <set>
// #include <vector>

size_t minimumLoss(
    std::vector<size_t> const & _prices
){
    auto pricesSorted = std::set<size_t>();
    pricesSorted.insert(_prices.at(0));
    pricesSorted.insert(_prices.at(1));
    auto minLoss = _prices.at(0) > _prices.at(1) ?
        _prices.at(0) - _prices.at(1) :
        std::numeric_limits<size_t>::max();
    auto updateMinLoss = [&](auto const & _price){
        auto newPrice = pricesSorted.insert(_price).first;
        minLoss = std::min(minLoss,
            newPrice == --std::cend(pricesSorted) ? minLoss :
                *++newPrice - _price);  
    };
    for_each(std::cbegin(_prices) + 2, std::cend(_prices), updateMinLoss);
    return minLoss; 
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string price_temp_temp;
    getline(cin, price_temp_temp);

    vector<string> price_temp = split(rtrim(price_temp_temp));

    vector<size_t> price(n);

    for (int i = 0; i < n; i++) {
        size_t price_item = stol(price_temp[i]);

        price[i] = price_item;
    }

    int result = minimumLoss(price);

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
