// problem: https://www.hackerrank.com/challenges/synchronous-shopping/problem?isFullScreen=true


#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'shop' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER k
 *  3. STRING_ARRAY centers
 *  4. 2D_INTEGER_ARRAY roads
 */

// #include <algorithm>
// #include <array>
// #include <queue>
// #include <vector>
// #include <utility>

constexpr size_t fishTypesCountMax{1'0 };
constexpr size_t shopsCountMax{1'000 + 1};
constexpr size_t fishTypesMaskMax{(1 << (fishTypesCountMax)) - 1};

size_t shop(
    size_t const shopsCount,
    size_t const fishTypesCount,
    std::vector<std::vector<size_t>> const & fishTypesAtShops,
    std::vector<std::vector<size_t>> const & roadsAndCosts
){
    using namespace std;
    using q_t = pair<size_t, pair<size_t, size_t>>; 
    auto shopToNeighboursAndCosts{array<vector<pair<size_t, size_t>>,
        ::shopsCountMax>{}};
    for(auto const roadAndCost : roadsAndCosts){
        shopToNeighboursAndCosts.at(roadAndCost.at(0)).emplace_back(
            roadAndCost.at(1), roadAndCost.at(2));
        shopToNeighboursAndCosts.at(roadAndCost.at(1)).emplace_back(
            roadAndCost.at(0), roadAndCost.at(2));
    }
    auto shopToFishTypesAvailable{array<size_t, ::shopsCountMax>{}};
    transform(begin(fishTypesAtShops), end(fishTypesAtShops),
        begin(shopToFishTypesAvailable) + 1, [&](auto const & fishTypes){
            return accumulate(begin(fishTypes) + 1, end(fishTypes), static_cast<size_t>(0),
                [&](auto startVal, auto fishType){
                    return startVal |= 1 << (fishType - 1);
                });
        });
    auto shopToFishTypesAccumulatedToShortestPath{array<array<size_t,
        ::fishTypesMaskMax + 1>, ::shopsCountMax>{}};
    for_each(begin(shopToFishTypesAccumulatedToShortestPath),
        end(shopToFishTypesAccumulatedToShortestPath),
        [&](auto & FishTypesAccumulatedToShortestPath){
            fill(begin(FishTypesAccumulatedToShortestPath), 
                end(FishTypesAccumulatedToShortestPath),
                numeric_limits<size_t>::max()
            );
        });
    auto dijkstraPQ{priority_queue<q_t, vector<q_t>, greater<q_t>>{}};
    dijkstraPQ.push({0, {1, shopToFishTypesAvailable.at(1)}});
    shopToFishTypesAccumulatedToShortestPath.at(1).at(
        shopToFishTypesAvailable.at(1)) = 0;
    while(!dijkstraPQ.empty()){
        auto shopCurrent{dijkstraPQ.top().second.first};
        auto costCurrent{dijkstraPQ.top().first};
        auto fishTypesAccumulatedCurrent{dijkstraPQ.top().second.second};
        dijkstraPQ.pop();
        if(costCurrent != shopToFishTypesAccumulatedToShortestPath.at(
                shopCurrent).at(fishTypesAccumulatedCurrent)
        ){
            continue;
        }
        for(auto const [neighbour, costNext]: shopToNeighboursAndCosts.at(
            shopCurrent)
        ){
            auto fishTypesAccumulatedNext{fishTypesAccumulatedCurrent |
                shopToFishTypesAvailable.at(neighbour)};
            if(shopToFishTypesAccumulatedToShortestPath.at(neighbour).at(
                    fishTypesAccumulatedNext) <= costCurrent + costNext
            ){
                continue;
            }
            shopToFishTypesAccumulatedToShortestPath.at(neighbour).at(
                fishTypesAccumulatedNext) = costCurrent + costNext;
            dijkstraPQ.push({shopToFishTypesAccumulatedToShortestPath.
                at(neighbour).at(fishTypesAccumulatedNext), {neighbour,
                    fishTypesAccumulatedNext}});
        }
    }
    auto timeMin{numeric_limits<size_t>::max()};
    for(size_t fishTypes1{0}; fishTypes1 <= ::fishTypesMaskMax; ++fishTypes1){
        for(auto fishTypes2{fishTypes1}; fishTypes2 <= ::fishTypesMaskMax;
            ++fishTypes2
        ){
            if((fishTypes1 | fishTypes2) !=
                (static_cast<size_t>(1) << fishTypesCount) - 1
            ){
                continue;
            }
            timeMin = min(timeMin, max(
                shopToFishTypesAccumulatedToShortestPath.at(shopsCount).at(
                    fishTypes1), shopToFishTypesAccumulatedToShortestPath.at(
                        shopsCount).at(fishTypes2)));
        }
    }
    return timeMin;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    int k = stoi(first_multiple_input[2]);

    vector<vector<size_t>> centers(n);

    for (int i = 0; i < n; i++) {
        string centers_item;
        getline(cin, centers_item);
        auto centers_item_str{split(rtrim(centers_item))};
        for(auto const & num: centers_item_str){
            centers.at(i).emplace_back(stoul(num));
        }
    }

    vector<vector<size_t>> roads(m);

    for (int i = 0; i < m; i++) {
        roads[i].resize(3);

        string roads_row_temp_temp;
        getline(cin, roads_row_temp_temp);

        vector<string> roads_row_temp = split(rtrim(roads_row_temp_temp));

        for (int j = 0; j < 3; j++) {
            auto  roads_row_item = static_cast<size_t>(stoi(roads_row_temp[j]));

            roads[i][j] = roads_row_item;
        }
    }

    int res = shop(static_cast<size_t>(n), static_cast<size_t>(k), centers, roads);

    fout << res << "\n";

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
