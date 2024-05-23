// problem: https://www.hackerrank.com/challenges/cut-the-tree/problem


#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'cutTheTree' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY data
 *  2. 2D_INTEGER_ARRAY edges
 */

// #include <algorithm>
// #include <cmath>
// #include <queue>
// #include <vector>

static constexpr int treeRoot = 0;

int cutTheTree(
    std::vector<int> & values,
    std::vector<std::vector<int>> const & graphEdges
){
    using namespace std;
    auto treeEdgesPossible{vector<vector<int>>(values.size(),
        vector<int>{})};
    for_each(begin(graphEdges), end(graphEdges), [&](auto & edge){
        treeEdgesPossible.at(edge.front() - 1).push_back(edge.back() - 1);
        treeEdgesPossible.at(edge.back() - 1).push_back(edge.front() - 1);
    });
    auto bfsQueue{queue<int>{}};
    auto treeEdgesActual{vector<pair<int, int>>{}};
    auto visited{vector<bool>(values.size(), false)};
    bfsQueue.push(treeRoot);
    visited.at(treeRoot) = true;
    while(!bfsQueue.empty()){
        for_each(cbegin(treeEdgesPossible.at(bfsQueue.front())),
            cend(treeEdgesPossible.at(bfsQueue.front())),
            [&](auto & childNode){
                if(visited.at(childNode)){
                    return;
                }
                visited.at(childNode) = true;
                bfsQueue.push(childNode);
                treeEdgesActual.emplace_back(bfsQueue.front(), childNode);
            }
        );
        bfsQueue.pop();
    }
    for_each(crbegin(treeEdgesActual), crend(treeEdgesActual), [&](auto treeEdge){
        values.at(treeEdge.first) += values.at(treeEdge.second);
    });
    auto absDiffMin = numeric_limits<int>::max();
    for_each(cbegin(values) + 1, cend(values), [&](auto const & value){
        absDiffMin = min(absDiffMin, abs(values.front() - 2 * value));
    });
    return absDiffMin;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string data_temp_temp;
    getline(cin, data_temp_temp);

    vector<string> data_temp = split(rtrim(data_temp_temp));

    vector<int> data(n);

    for (int i = 0; i < n; i++) {
        int data_item = stoi(data_temp[i]);

        data[i] = data_item;
    }

    vector<vector<int>> edges(n - 1);

    for (int i = 0; i < n - 1; i++) {
        edges[i].resize(2);

        string edges_row_temp_temp;
        getline(cin, edges_row_temp_temp);

        vector<string> edges_row_temp = split(rtrim(edges_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int edges_row_item = stoi(edges_row_temp[j]);

            edges[i][j] = edges_row_item;
        }
    }

    int result = cutTheTree(data, edges);

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
