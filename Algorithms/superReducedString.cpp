// problem : https://www.hackerrank.com/challenges/reduced-string/problem?isFullScreen=true


#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'superReducedString' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

// #include <string>

string superReducedString(string s) {
    if(s.size() == 1)
    { 
        return s;
    } 
    std::string reduced;
    reduced.push_back(s.front());
    s.erase(std::begin(s));
    while(!s.empty())
    {
        if(reduced.back() == s.front())
        {
            reduced.pop_back();
        } else {
            reduced.push_back(s.front());
        }
        s.erase(0, 1);
    }
    return reduced.empty() ? "Empty String" : reduced;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = superReducedString(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
