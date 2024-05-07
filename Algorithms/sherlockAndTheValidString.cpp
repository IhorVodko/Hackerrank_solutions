// problem: https://www.hackerrank.com/challenges/sherlock-and-valid-string/problem?isFullScreen=true


#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'isValid' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

// #include <cstdlib>
// #include <string>
// #include <unordered_map>

std::string isValid(
    std::string const & _str
){
    assert(!_str.empty());
    auto charFrqncs = std::unordered_map<char, size_t>();
    for(auto & chr : _str){
        ++charFrqncs[chr];
    }
    auto frqncFrqncs = std::unordered_map<
        decltype(charFrqncs)::mapped_type, size_t>();
    for([[maybe_unused]] auto const & [_, frqnc]: charFrqncs){
        ++frqncFrqncs[frqnc];
    }
    if(frqncFrqncs.size() == 1){
        return "YES";
    }
    if(frqncFrqncs.size() != 2 ){
        return "NO";
    }
    auto const & [frqnc1, frqncOfFrqnc1] = *std::cbegin(frqncFrqncs);
    auto const & [frqnc2, frqncOfFrqnc2] = *++std::cbegin(frqncFrqncs);
    auto const frequincyDiff = std::abs(static_cast<int>(
        frqnc1 - frqnc2));  
    return 
        (frqnc1 == 1 && frqncOfFrqnc1 == 1) ||
        (frqnc2 == 1 && frqncOfFrqnc2 == 1) ||
        ((frqncOfFrqnc1 == 1 || frqncOfFrqnc2 == 1) && 
            frequincyDiff == 1)
        ? "YES" : "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
