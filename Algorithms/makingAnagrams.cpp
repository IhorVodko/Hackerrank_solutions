// problem : https://www.hackerrank.com/challenges/making-anagrams/problem?isFullScreen=true


#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'makingAnagrams' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING s1
 *  2. STRING s2
 */

// #include <algorithm>
// #include <exception>
// #include <iterator>
// #include <string>

int makingAnagrams(
        std::string _s1
    ,   std::string _s2
){
    size_t minDeletions = 0;
    std::sort(_s1.begin(), _s1.end());
    std::sort(_s2.begin(), _s2.end());
    auto it1 = _s1.cbegin();
    auto it2 = _s2.cbegin();
    while(it1 != _s1.cend() && it2 != _s2.cend()){
        if(*it1 < *it2){
            ++minDeletions;
            ++it1;
        }else if(*it1 > *it2){
            ++minDeletions;
            ++it2;
        }else{
            ++it1;
            ++it2;
        }
    }
    return minDeletions += it1 == _s1.cend() 
        ? std::distance(it2, _s2.cend()) 
        : std::distance(it1, _s1.cend())
    ;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    int result = makingAnagrams(s1, s2);

    fout << result << "\n";

    fout.close();

    return 0;
}
