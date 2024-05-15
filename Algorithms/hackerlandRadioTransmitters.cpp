// problem: https://www.hackerrank.com/challenges/hackerland-radio-transmitters/problem?isFullScreen=true


#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'hackerlandRadioTransmitters' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY x
 *  2. INTEGER k
 */

// #include <algorithm>
// #include <vector>

int hackerlandRadioTransmitters(
    std::vector<int> const & _houseLocations,
    int const & _range
){
    size_t const coverageArea = _range * 2 + 1;
    auto houseLocations = std::vector<bool>(std::pow(10,5) + 1, false);
    auto lastLocation = 0;
    auto firstLocation = static_cast<int>(std::pow(10,5));
    for(auto const & location: _houseLocations){
        firstLocation = std::min(firstLocation, location);
        lastLocation = std::max(lastLocation, location);
        houseLocations.at(location) = true;
    }
    size_t transmitters = 0;
    for(auto first = std::cbegin(houseLocations) + firstLocation;
        first < std::cbegin(houseLocations) + lastLocation + 1; ++first
    ){
        if(!*first){
            continue;
        }
        ++transmitters;
        if(*(first + _range)){
            std::advance(first, coverageArea - 1);
        }else{
            first = find_end(first, first + _range, first, first + 1);
            std::advance(first, _range);
        }
    }
    return transmitters;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string x_temp_temp;
    getline(cin, x_temp_temp);

    vector<string> x_temp = split(rtrim(x_temp_temp));

    vector<int> x(n);

    for (int i = 0; i < n; i++) {
        int x_item = stoi(x_temp[i]);

        x[i] = x_item;
    }

    int result = hackerlandRadioTransmitters(x, k);

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
