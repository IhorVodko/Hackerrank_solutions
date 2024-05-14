// problem: https://www.hackerrank.com/challenges/common-child/problem?isFullScreen=true


#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'commonChild' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING s1
 *  2. STRING s2
 */

// #include <algorithm>
// #include <cassert>
// #include <string>

int commonChild(
    std::string const & _str1,
    std::string const & _str2
){
    assert(_str1.size() == _str2.size());
    auto longestCommonSequence = std::vector<std::vector<size_t>>(
        2, std::vector<size_t>(_str1.size() + 1, 0));
    size_t row = 1;
    size_t col = 1;
    bool isLastRow = true;
    for(auto char1 = std::begin(_str1); char1 != std::end(_str1);
        ++char1
    ){
        row =  isLastRow ? 1 : 0;
        col = 1;
        for(auto char2 = std::begin(_str2); char2 != std::end(_str2);
            ++char2
        ){
            if(*char1 == *char2){
                longestCommonSequence.at(row).at(col) =
                    longestCommonSequence.at(
                        isLastRow ? row - 1 : row + 1).at(col - 1) + 1;
            }else{
                longestCommonSequence.at(row).at(col) = std::max(
                    longestCommonSequence.at(
                        isLastRow ? row - 1 : row + 1).at(col),
                    longestCommonSequence.at(row).at(col - 1)); 
            }
            ++col;   
        }
        isLastRow = !isLastRow;
    }
    return isLastRow ? longestCommonSequence.front().back() :
        longestCommonSequence.back().back();
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    int result = commonChild(s1, s2);

    fout << result << "\n";

    fout.close();

    return 0;
}
