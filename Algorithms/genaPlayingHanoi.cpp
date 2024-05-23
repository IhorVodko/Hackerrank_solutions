// problem: https://www.hackerrank.com/challenges/gena/problem?isFullScreen=true


#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'hanoi' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY posts as parameter.
 */

// #include <algorithm>
// #include <vector>
// #include <queue>

static const size_t rodsCount = 4;
static const size_t statesMaxCount = static_cast<size_t>(std::pow(4, 10)); 

size_t hanoi(
    std::vector<size_t> const & positions
){
    using namespace std;
    using state_t = vector<size_t>;
    using mask_t = vector<bool>;
    auto const & disksCount{positions.size()};
    // last element of a vector tracks how many moves done to achive its state
    auto stateAtTreeRoot(state_t(disksCount + 1, 0));
    transform(cbegin(positions), cend(positions), begin(stateAtTreeRoot),
        [&](const auto & disk){
            return disk - 1;
        });
    auto bfsQ{queue<state_t>{}};
    bfsQ.push(stateAtTreeRoot);
    auto statesAtTreeVisited{mask_t(::statesMaxCount, false)};
    auto hash = [&](auto const & value){
        size_t hashValue{0};
        for_each(cbegin(value), cend(value) - 1, [&](auto const & num){
            hashValue = hashValue * ::rodsCount + num;
        });
        return hashValue;
    };
    statesAtTreeVisited.at(hash(stateAtTreeRoot)) = true;
    auto rodsVisitedToMoveFrom{mask_t(::rodsCount, false)};
    auto rodsVisitedToMoveTo{mask_t(::rodsCount, false)};
    size_t hashValue{0};
    auto stateAtSubTreeRoot{state_t(disksCount + 1, 0)};
    auto stateAtNextNode{state_t(disksCount + 1, 0)};
    while(!bfsQ.empty()){
        copy(cbegin(bfsQ.front()), cend(bfsQ.front()),
            begin(stateAtSubTreeRoot));
        bfsQ.pop();
        for(size_t disk{0}; disk < disksCount; ++disk){
            if(rodsVisitedToMoveFrom.at(stateAtSubTreeRoot.at(disk))){
               continue; 
            }
            rodsVisitedToMoveFrom.at(stateAtSubTreeRoot.at(disk)) = true;
            copy(cbegin(rodsVisitedToMoveFrom), cend(rodsVisitedToMoveFrom),
                begin(rodsVisitedToMoveTo));
            for(size_t newRod{0}; newRod < ::rodsCount; ++newRod){
                if(rodsVisitedToMoveTo.at(newRod)){
                    continue;
                }
                rodsVisitedToMoveTo.at(newRod) = true;
                copy(cbegin(stateAtSubTreeRoot), cend(stateAtSubTreeRoot),
                    begin(stateAtNextNode));
                ++stateAtNextNode.back();
                stateAtNextNode.at(disk) = newRod;
                hashValue = hash(stateAtNextNode);
                if(hashValue == 0){
                    return stateAtNextNode.back();
                }
                if(statesAtTreeVisited.at(hashValue)){
                    continue;
                }
                statesAtTreeVisited.at(hashValue) = true;
                bfsQ.push(stateAtNextNode);
            }
            fill(begin(rodsVisitedToMoveTo), end(rodsVisitedToMoveTo),
                false);
        }
        fill(begin(rodsVisitedToMoveFrom), end(rodsVisitedToMoveFrom),
            false);
    }
    return numeric_limits<size_t>::max();
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string loc_temp_temp;
    getline(cin, loc_temp_temp);

    vector<string> loc_temp = split(rtrim(loc_temp_temp));

    vector<size_t> loc(n);

    for (int i = 0; i < n; i++) {
        auto loc_item = stoul(loc_temp[i]);

        loc[i] = loc_item;
    }

    auto res = hanoi(loc);

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
