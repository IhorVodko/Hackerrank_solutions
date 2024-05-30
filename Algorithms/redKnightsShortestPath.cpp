// problem: https://www.hackerrank.com/challenges/red-knights-shortest-path/problem?isFullScreen=true


#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'printShortestPath' function below.
 *
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER i_start
 *  3. INTEGER j_start
 *  4. INTEGER i_end
 *  5. INTEGER j_end
 */

// #include <algorithm>
// #include <queue>
// #include <iostream>
// #include <memory>
// #include <map>
// #include <string>
// #include <unordered_map>

constexpr char IMPOSSIBLE[] = "Impossible";

enum class MoveDirections{
    UL, UR, R, LR, LL, L, START, DEFAULT 
};

auto const moves{std::map<::MoveDirections, std::pair<int, int>>{
    {MoveDirections::UL, {-2, -1}}, {MoveDirections::UR, {-2, 1}},
    {MoveDirections::R, {0, 2}}, {MoveDirections::LR, {2, 1}},
    {MoveDirections::LL, {2, -1}}, {MoveDirections::L, {0, -2}},
}};

auto const movesPrint{std::unordered_map<::MoveDirections, std::string>{
    {MoveDirections::UL, "UL"}, {MoveDirections::UR, "UR"},
    {MoveDirections::R, "R"}, {MoveDirections::LR, "LR"},
    {MoveDirections::LL, "LL"}, {MoveDirections::L, "L"}
}};

struct Node{
    using mD = MoveDirections;
    Node(): 
        row{0},
        col{0},
        direction{mD::DEFAULT},
        parent{},
        childs{}
    {}
    Node(
        int const rNew,
        int const cNew,
        mD const newDirection,
        std::shared_ptr<Node const> && newParent = nullptr
    ):
        row{rNew},
        col{cNew},
        direction{newDirection},
        parent{newParent},
        childs{}
    {}
    int row;
    int col;
    MoveDirections direction;
    std::shared_ptr<Node const> parent;
    mutable std::vector<std::shared_ptr<Node const>> childs;
};

void printShortestPath(
    int const size,
    int const rStart, 
    int const cStart, 
    int const rEnd,
    int const cEnd
){
    using namespace  std;
    using  mD = ::MoveDirections;
    auto boardFree{vector<vector<bool>>(size, vector<bool>(size, true))};
    auto root{make_shared<Node const>(rStart, cStart, mD::START)};
    auto qBFS(queue<shared_ptr<Node const>>{});
    qBFS.push(root);
    auto nodeCurrent{decltype(qBFS)::value_type{}};
    auto rNew{0};
    auto cNew{0};
    while(!qBFS.empty()){
        nodeCurrent = std::move(qBFS.front());
        qBFS.pop();
        for(auto const & [direction, move]: moves){
            rNew = nodeCurrent->row + move.first;
            cNew = nodeCurrent->col + move.second;
            if(!(0 <= rNew && rNew < size && 0 <= cNew &&
                cNew < size && boardFree.at(rNew).at(cNew))
            ){
                continue;
            }
            boardFree.at(rNew).at(cNew) = false;
            nodeCurrent->childs.emplace_back(make_shared<Node const>(
                rNew, cNew, direction, std::move(nodeCurrent)));
            qBFS.push(nodeCurrent->childs.back());
            if(!(rNew == rEnd && cNew == cEnd)){
                continue;
            }
            auto steps{0};
            auto pathReverse{vector<mD>{}};
            nodeCurrent = nodeCurrent->childs.back();
            while(nodeCurrent->parent){
                ++steps;
                pathReverse.emplace_back(nodeCurrent->direction);
                nodeCurrent = nodeCurrent->parent;
            }
            cout << steps << '\n';
            transform(crbegin(pathReverse), crend(pathReverse), 
                ostream_iterator<string>(cout, " "), [&](auto const & direction){
                    return  movesPrint.at(direction);
                });
            return;
        }
    }
    cout << IMPOSSIBLE;
}


int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int i_start = stoi(first_multiple_input[0]);

    int j_start = stoi(first_multiple_input[1]);

    int i_end = stoi(first_multiple_input[2]);

    int j_end = stoi(first_multiple_input[3]);

    printShortestPath(n, i_start, j_start, i_end, j_end);

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
