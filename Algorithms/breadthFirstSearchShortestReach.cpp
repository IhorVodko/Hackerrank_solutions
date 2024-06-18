// problem: https://www.hackerrank.com/challenges/bfsshortreach/problem?isFullScreen=true


#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'bfs' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER m
 *  3. 2D_INTEGER_ARRAY edges
 *  4. INTEGER s
 */

// #include <queue>
// #include <vector>

std::vector<int> bfs(
    int const nodesCount,
    int const edgesCount,
    std::vector<std::vector<int>> const & edges,
    int const nodeStart
){
    using namespace std;
    static constexpr auto edgeCost{6};
    static constexpr auto startNodePathCost{0};
    static constexpr auto isolatedNodePathCost{-1};
    auto nodeToNeighbours{vector<vector<size_t>>(nodesCount + 1,
        vector<size_t>{})};
    for(auto const & edge: edges){
        nodeToNeighbours.at(edge.at(0)).emplace_back(edge.at(1));
        nodeToNeighbours.at(edge.at(1)).emplace_back(edge.at(0));
    }
    auto qNodes{queue<size_t>{}};
    qNodes.push(nodeStart);
    auto pathesShortest{vector<int>(nodesCount + 1, -1)};
    pathesShortest.at(nodeStart) = startNodePathCost;
    auto nodeCurrent{numeric_limits<size_t>::max()};
    auto pathCostNext{numeric_limits<size_t>::max()};
    while(!qNodes.empty()){
        nodeCurrent = qNodes.front();
        pathCostNext = pathesShortest.at(nodeCurrent) + edgeCost;
        qNodes.pop();
        for(auto const & nodeNext: nodeToNeighbours.at(nodeCurrent)){
            if(pathesShortest.at(nodeNext) != isolatedNodePathCost){
                continue;
            }
            qNodes.push(nodeNext);
            pathesShortest.at(nodeNext) = pathCostNext;
        }
    }
    pathesShortest.erase(begin(pathesShortest) + nodeStart);
    pathesShortest.erase(begin(pathesShortest));
    return pathesShortest;
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

        vector<vector<int>> edges(m);

        for (int i = 0; i < m; i++) {
            edges[i].resize(2);

            string edges_row_temp_temp;
            getline(cin, edges_row_temp_temp);

            vector<string> edges_row_temp = split(rtrim(edges_row_temp_temp));

            for (int j = 0; j < 2; j++) {
                int edges_row_item = stoi(edges_row_temp[j]);

                edges[i][j] = edges_row_item;
            }
        }

        string s_temp;
        getline(cin, s_temp);

        int s = stoi(ltrim(rtrim(s_temp)));

        vector<int> result = bfs(n, m, edges, s);

        for (size_t i = 0; i < result.size(); i++) {
            fout << result[i];

            if (i != result.size() - 1) {
                fout << " ";
            }
        }

        fout << "\n";
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
