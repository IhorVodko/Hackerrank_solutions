// problem: https://www.hackerrank.com/challenges/journey-to-the-moon/problem?isFullScreen=true


#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'journeyToMoon' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY astronaut
 */

// #include <queue>
// #include <vector>
// #include <unordered_map>

size_t journeyToMoon(
    int idCount,
    std::vector<std::vector<int>> const & idPairs
){
    using namespace std;
    using ids_t = remove_cv_t<remove_reference_t<decltype(idPairs)>>::
        value_type;
    using id_t = ids_t::value_type;
    auto idsFromSameCountry{unordered_map<id_t, ids_t>{}};
    for(auto const & idPair: idPairs){
        idsFromSameCountry[idPair.at(0)].emplace_back(idPair.at(1));
        idsFromSameCountry[idPair.at(1)].emplace_back(idPair.at(0));
    }
    auto visitedBfs{vector<bool>(idCount, false)};
    auto idCountsPerCountry{unordered_map<int, int>{}};
    auto idCountry{0};
    auto qBfs{queue<id_t>{}};
    for(auto const & ids: idsFromSameCountry){
        if(visitedBfs.at(ids.first)){
            continue;
        }
        qBfs = queue<id_t>{};
        qBfs.push(ids.first);
        visitedBfs.at(ids.first) = true;
        ++idCountsPerCountry[++idCountry];
        while(!qBfs.empty()){
            for(auto const id: idsFromSameCountry.at(qBfs.front())){
                if(visitedBfs.at(id)){
                    continue;
                }
                qBfs.push(id);
                ++idCountsPerCountry.at(idCountry);
                visitedBfs.at(id) = true;
            }
            qBfs.pop();
        }
    }
    auto singleIdPerCountryCount{idCount - idsFromSameCountry.size()};
    while(singleIdPerCountryCount--){
        idCountsPerCountry[++idCountry] = 1;
    }
    size_t idFromDiffCountriesPairCount{0};
    for(auto const [_, idCountPerCountry]: idCountsPerCountry){
        idCount -= idCountPerCountry;
        idFromDiffCountriesPairCount += idCountPerCountry * idCount;    
    }
    return idFromDiffCountriesPairCount;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int p = stoi(first_multiple_input[1]);

    vector<vector<int>> astronaut(p);

    for (int i = 0; i < p; i++) {
        astronaut[i].resize(2);

        string astronaut_row_temp_temp;
        getline(cin, astronaut_row_temp_temp);

        vector<string> astronaut_row_temp = split(rtrim(astronaut_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int astronaut_row_item = stoi(astronaut_row_temp[j]);

            astronaut[i][j] = astronaut_row_item;
        }
    }

    // int result = journeyToMoon(n, astronaut);
    auto result = journeyToMoon(n, astronaut);

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
