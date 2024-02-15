// problem : https://www.hackerrank.com/challenges/camelcase/problem?isFullScreen=true


#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'camelcase' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

// #include <algorithm>
// #include <cctype>

int camelcase(std::string const & _str) {
    return static_cast<int>(std::count_if(
            std::cbegin(_str)
        ,   std::cend(_str)
        ,   [](char const & _char){ return isupper(_char); }
    )) + 1;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int result = camelcase(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
