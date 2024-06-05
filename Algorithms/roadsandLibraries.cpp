// problem: https://www.hackerrank.com/challenges/torque-and-development/problem?isFullScreen=true


#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'roadsAndLibraries' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER c_lib
 *  3. INTEGER c_road
 *  4. 2D_INTEGER_ARRAY cities
 */

// #include <queue>
// #include <vector>

long roadsAndLibraries(
    int const & citiesCount,
    int const & costLib, 
    int const & costRoad,
    std::vector<std::vector<int>> const & roads
){
    using namespace std;
    if(costLib <= costRoad){
        return static_cast<long>(citiesCount) * costLib;
    }
    auto citiesConnected{unordered_map<int, vector<int>>{}};
    for(auto const & road: roads){
        citiesConnected[road.at(0)].emplace_back(road.at(1)); 
        citiesConnected[road.at(1)].emplace_back(road.at(0)); 
    }
    auto citiesVisited{vector<bool>(citiesCount, false)};
    auto isolatedRegions{0};
    auto doBFS = [&](auto const & city){
        auto qBFS{queue<int>{}};
        qBFS.push(city);
        citiesVisited.at(city - 1) = true;
        while(!qBFS.empty()){
            for(auto const & neighbour: citiesConnected.at(qBFS.front())){
                if(citiesVisited.at(neighbour - 1)){
                   continue; 
                }
                qBFS.push(neighbour);
                citiesVisited.at(neighbour - 1) = true;
            }
            qBFS.pop();
        }
    };
    for(auto const & [city, _]: citiesConnected){
        if(citiesVisited.at(city - 1)){
            continue;
        }
        doBFS(city);
        ++isolatedRegions;
    }
    isolatedRegions += citiesCount - citiesConnected.size();
    return isolatedRegions * static_cast<long>(costLib) +
        (citiesCount - isolatedRegions) * static_cast<long>(costRoad);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int n = stoi(first_multiple_input[0]);

        int m = stoi(first_multiple_input[1]);

        int c_lib = stoi(first_multiple_input[2]);

        int c_road = stoi(first_multiple_input[3]);

        vector<vector<int>> cities(m);

        for (int i = 0; i < m; i++) {
            cities[i].resize(2);

            string cities_row_temp_temp;
            getline(cin, cities_row_temp_temp);

            vector<string> cities_row_temp = split(rtrim(cities_row_temp_temp));

            for (int j = 0; j < 2; j++) {
                int cities_row_item = stoi(cities_row_temp[j]);

                cities[i][j] = cities_row_item;
            }
        }

        long result = roadsAndLibraries(n, c_lib, c_road, cities);

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
