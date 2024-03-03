// problem : https://www.hackerrank.com/challenges/mars-exploration/problem?isFullScreen=true


#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'marsExploration' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

// #include <string>

int marsExploration(std::string const & _str) {
    int diff{0};
    for(auto i{0}; i < _str.size(); ++i){
        if(
                (i - 1) % 3 == 0 
            ?   _str[i] != 'O'
            :   _str[i] != 'S'
        ){
            ++diff;
        }
    }
    return diff;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int result = marsExploration(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
