// problem: https://www.hackerrank.com/challenges/short-palindrome/problem?isFullScreen=true


#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'shortPalindrome' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

// #include <cmath>
// #include <string>
// #include <vector>

static size_t const alphabetSize{26};
static size_t const aASCII{97};
static size_t const modulo{static_cast<size_t>(std::pow(10, 9)) + 7};

size_t shortPalindrome(
    std::string const & str
){
    using namespace std;
    size_t tuplesCount = 0;
    auto char1{vector<size_t>(alphabetSize, 0)}; 
    auto chars12{vector<size_t>(alphabetSize * alphabetSize, 0)}; 
    auto chars123{vector<size_t>(alphabetSize, 0)};
    size_t chNum{0};
    size_t chCopy{0};
    for(auto const & ch: str){
        chNum = static_cast<size_t>(ch) - aASCII;
        chCopy = chNum;
        tuplesCount = (tuplesCount % modulo) + chars123.at(chCopy);
        for(auto i = 0; i < alphabetSize; ++i){
            chars123.at(i) += chars12.at(chCopy);
            chars12.at(chCopy) += char1.at(i);
            chCopy += 26;
        }
        ++char1.at(chNum);
    } 
    return tuplesCount % modulo;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    auto result = shortPalindrome(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
