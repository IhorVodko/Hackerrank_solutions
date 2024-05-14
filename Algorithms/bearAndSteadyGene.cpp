// problem: https://www.hackerrank.com/challenges/bear-and-steady-gene/problem?isFullScreen=true


#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'steadyGene' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING gene as parameter.
 */

// #include <algorithm>
// #include <string>
// #include <unordered_map>

int steadyGene(
    std::string const & _gene
){
    auto chrCounts = std::unordered_map<char, size_t>();
    for(auto const & chr : _gene){
        ++chrCounts[chr];    
    }
    size_t minPossibleLength = 0;
    auto steadyCount = _gene.size() / 4;
    for(auto const & [_, count]: chrCounts){
        if(count > steadyCount){
            minPossibleLength += count - steadyCount;
        }
    } 
    auto minLength = _gene.size() - steadyCount;
    for(auto first = std::begin(_gene), last = first;
        last != std::end(_gene);
    ){
        --chrCounts.at(*last++);
        while(std::all_of(std::begin(chrCounts), std::end(chrCounts),
            [&](auto const & _chrCount){
                return _chrCount.second <= steadyCount;}
        )){
            minLength = std::min(minLength, static_cast<size_t>(
                std::distance(first, last)));
            if(minLength == minPossibleLength){
                return minLength;
            }
            ++chrCounts.at(*first++);
        }
    }
    return minLength;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    // int n = stoi(ltrim(rtrim(n_temp)));

    string gene;
    getline(cin, gene);

    int result = steadyGene(gene);

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
