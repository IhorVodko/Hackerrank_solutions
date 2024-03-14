// problem : https://www.hackerrank.com/challenges/game-of-thrones/problem?isFullScreen=true


#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'gameOfThrones' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

// #include <algorithm>
// #include <string>

std::string gameOfThrones(std::string _key){
    if(_key.size() == 1){
        return "YES";
    }
    bool isMedianFound = false;
    bool isSzEven = !_key.size() % 2;
    std::sort(_key.begin(), _key.end());
    for(auto it1 = _key.cbegin(), it2 = it1 + 1; it1 != _key.cend(); ++it2){
        if(*it1 == *it2){
            it1 = ++it2;
        }else{
            if(isMedianFound || isSzEven){
                return "NO";
            }
            isMedianFound = true;
            it1 = it2;
        }
    }
    return "YES";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = gameOfThrones(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
