// problem : https://www.hackerrank.com/challenges/pangrams/problem?isFullScreen=true


#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'pangrams' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

// #include <set>
// #include <string>
// #include <cctype>

std::string pangrams(std::string const & _str) {
    static constexpr auto alphabetSize = 26;
    std::set<char> alphabet;
    for(auto const & chr : _str){
        if(isalpha(chr)){
            alphabet.insert(tolower(chr));
        }
    }
    return alphabet.size() == alphabetSize ? "pangram" : "not pangram";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = pangrams(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
