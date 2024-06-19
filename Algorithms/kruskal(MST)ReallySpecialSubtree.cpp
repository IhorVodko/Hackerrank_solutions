// problem: https://www.hackerrank.com/challenges/kruskalmstrsub/problem?isFullScreen=true


#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'kruskals' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts WEIGHTED_INTEGER_GRAPH g as parameter.
 */

/*
 * For the weighted graph, <name>:
 *
 * 1. The number of nodes is <name>_nodes.
 * 2. The number of edges is <name>_edges.
 * 3. An edge exists between <name>_from[i] and <name>_to[i]. The weight of the edge is <name>_weight[i].
 *
 */

// #include <queue>
// #include <map>
// #include <vector>
// #include <unordered_map>


bool areNodesInTheSameTree(
    vector<bool> const & nodesVisited,
    std::unordered_map<int, vector<int>> const & nodeToNeighbours,
    int const nodeA,
    int const nodeB,
    int const nodesCount
){
    using namespace std;
    if(!(nodesVisited.at(nodeA) && nodesVisited.at(nodeB))){
        return false;
    }
    auto nodesVisitedBfs{vector<bool>(nodesCount + 1, false)};
    auto qBfs{queue<int>{}};
    qBfs.push(nodeA);
    nodesVisitedBfs.at(nodeA) = true;
    auto nodeCurrent{qBfs.front()};
    while(!qBfs.empty()){
        nodeCurrent = qBfs.front();
        qBfs.pop();
        for(auto const nodeNext: nodeToNeighbours.at(nodeCurrent)){
            if(nodeNext == nodeB){
                return true;
            }
            if(nodesVisitedBfs.at(nodeNext)){
                continue;
            }
            qBfs.push(nodeNext);
            nodesVisitedBfs.at(nodeNext) = true;
        }
    }
    return false;
}

int kruskals(
    int const nodesCount,
    std::vector<int> const & nodesFrom,
    std::vector<int> const & nodesTo,
    std::vector<int> const & edgeWeightes
){
    using namespace  std;
    auto weightToEdges{multimap<int, pair<int, int>>{}};
    for(size_t idx{0}; idx != edgeWeightes.size(); ++idx){
        weightToEdges.insert({edgeWeightes.at(idx), {nodesFrom.at(idx),
            nodesTo.at(idx)}});
    }
    cout << weightToEdges.size() << '\n';
    auto nodeToNeighbours{unordered_map<int, vector<int>>{}};
    auto weightSubtree{0};
    auto nodesVisited{vector<bool>(nodesCount + 1, false)};
    for(auto const & [weight, edge]: weightToEdges){
        if(::areNodesInTheSameTree(nodesVisited, nodeToNeighbours, edge.first,
            edge.second, nodesCount)
        ){
            continue;
        }
        nodeToNeighbours[edge.first].emplace_back(edge.second);
        nodeToNeighbours[edge.second].emplace_back(edge.first);
        nodesVisited.at(edge.first) = true;
        nodesVisited.at(edge.second) = true;
        weightSubtree += weight;
    }
    return weightSubtree;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string g_nodes_edges_temp;
    getline(cin, g_nodes_edges_temp);

    vector<string> g_nodes_edges = split(rtrim(g_nodes_edges_temp));

    int g_nodes = stoi(g_nodes_edges[0]);
    int g_edges = stoi(g_nodes_edges[1]);

    vector<int> g_from(g_edges);
    vector<int> g_to(g_edges);
    vector<int> g_weight(g_edges);

    for (int i = 0; i < g_edges; i++) {
        string g_from_to_weight_temp;
        getline(cin, g_from_to_weight_temp);

        vector<string> g_from_to_weight = split(rtrim(g_from_to_weight_temp));

        int g_from_temp = stoi(g_from_to_weight[0]);
        int g_to_temp = stoi(g_from_to_weight[1]);
        int g_weight_temp = stoi(g_from_to_weight[2]);

        g_from[i] = g_from_temp;
        g_to[i] = g_to_temp;
        g_weight[i] = g_weight_temp;
    }

    int res = kruskals(g_nodes, g_from, g_to, g_weight);
    fout << res;
    // Write your code here.

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
