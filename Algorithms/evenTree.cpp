// problem: https://www.hackerrank.com/challenges/even-tree/problem?isFullScreen=true


#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// Complete the evenForest function below.
// #include <algorithm>
// #include <queue>
// #include <limits>
// #include <vector>
// #include <unordered_map>

using Node_t = int;
using Nodes_t = std::vector<::Node_t>;
using NodesQueue_t = std::queue<::Node_t>;
using NodesMap_t = std::unordered_map<::Node_t, ::Nodes_t>;

constexpr Node_t nodeRoot{1};
constexpr Node_t nodeDummy{0};

bool IsValidTreeCut(
    ::NodesMap_t &,
    ::Node_t const,
    ::Node_t const  
);

bool IsNodesCountEven(
    ::NodesMap_t &,
    ::Node_t const
);

int evenForest(
    ::Node_t const nodesCount,
    ::Node_t const edgesCount,
    ::Nodes_t const & nodesFrom,
    ::Nodes_t const & nodesTo
){
    using namespace std;
    auto nodeToNeighbours{::NodesMap_t{}};
    nodeToNeighbours[::nodeDummy] = ::Nodes_t{};
    for(size_t idx{0}; idx < nodesFrom.size(); ++idx){
        nodeToNeighbours[nodesFrom.at(idx)].emplace_back(nodesTo.at(idx));
        nodeToNeighbours[nodesTo.at(idx)].emplace_back(nodesFrom.at(idx));
    }
    auto qBfs{::NodesQueue_t{}};
    auto nodesVisited{vector<bool>(nodeToNeighbours.size(), false)};
    qBfs.push(::nodeRoot);
    nodesVisited.at(::nodeRoot) = true;
    nodesVisited.at(::nodeDummy) = true;
    auto nodeCurrent{numeric_limits<::Node_t>::max()};
    auto cutsCount{0};
    while(!qBfs.empty()){
        nodeCurrent = qBfs.front();
        qBfs.pop();
        for(auto const nodeNext: nodeToNeighbours.at(nodeCurrent)){
            if(nodesVisited.at(nodeNext)){
                continue;
            }
            qBfs.push(nodeNext);
            nodesVisited.at(nodeNext) = true;
            if(::IsValidTreeCut(nodeToNeighbours, nodeCurrent, nodeNext)){
                ++cutsCount;
            }
        }
    }
    return cutsCount;
}

bool IsValidTreeCut(
    ::NodesMap_t & nodeToNeighbours,
    ::Node_t const nodeParent,
    ::Node_t const nodeNewRoot 
){
    using namespace std;
    auto & nodesNeighboursA{nodeToNeighbours.at(nodeNewRoot)};
    auto nodeParentIter{find(begin(nodesNeighboursA), end(nodesNeighboursA),
        nodeParent)};
    if(nodeParentIter == end(nodesNeighboursA)){
        return false;
    }
    *nodeParentIter = ::nodeDummy; 
    auto & nodesNeighboursB{nodeToNeighbours.at(nodeParent)};
    auto nodeNewRootIter{find(begin(nodesNeighboursB), end(nodesNeighboursB),
        nodeNewRoot)};
    if(nodeNewRootIter == end(nodesNeighboursB)){
        return false;
    }
    *nodeNewRootIter = ::nodeDummy;
    if(::IsNodesCountEven(nodeToNeighbours, nodeNewRoot)){
        return true;
    }
    *nodeParentIter = nodeParent;
    *nodeNewRootIter = nodeNewRoot;
    return false;
}

bool IsNodesCountEven(
    ::NodesMap_t & nodeToNeighbours,
    ::Node_t const nodeNewRoot
){
    using namespace std;
    auto qBfs{::NodesQueue_t{}};
    auto nodesVisited{vector<bool>(nodeToNeighbours.size(), false)};
    qBfs.push(nodeNewRoot);
    nodesVisited.at(nodeNewRoot) = true;
    nodesVisited.at(nodeDummy) = true;
    auto nodeCurrent{numeric_limits<::Node_t>::max()};
    size_t nodesCount{1};
    while(!qBfs.empty()){
        nodeCurrent = qBfs.front();
        qBfs.pop();
        for(auto const nodeNext: nodeToNeighbours.at(nodeCurrent)){
            if(nodesVisited.at(nodeNext)){
                continue;
            }
            qBfs.push(nodeNext);
            ++nodesCount;
            nodesVisited.at(nodeNext) = true;   
        }
    }
    return nodesCount % 2 == 0;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_nodes_edges_temp;
    getline(cin, t_nodes_edges_temp);

    vector<string> t_nodes_edges = split(rtrim(t_nodes_edges_temp));

    int t_nodes = stoi(t_nodes_edges[0]);
    int t_edges = stoi(t_nodes_edges[1]);

    vector<int> t_from(t_edges);
    vector<int> t_to(t_edges);

    for (int i = 0; i < t_edges; i++) {
        string t_from_to_temp;
        getline(cin, t_from_to_temp);

        vector<string> t_from_to = split(rtrim(t_from_to_temp));

        int t_from_temp = stoi(t_from_to[0]);
        int t_to_temp = stoi(t_from_to[1]);

        t_from[i] = t_from_temp;
        t_to[i] = t_to_temp;
    }

    int res = evenForest(t_nodes, t_edges, t_from, t_to);

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
