// problem : https://www.hackerrank.com/challenges/nimble-game-1/problem?isFullScreen=true


#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'nimbleGame' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts INTEGER_ARRAY s as parameter.
 */

// #include <string>
// #include <vector>

std::string nimbleGame(std::vector<int> _squares){
    int binSum = 0;
    for(auto i = 0; i != _squares.size(); ++i){
        if(_squares[i] % 2 == 1){
            binSum ^= i;
        }
    }
    return binSum ? "First" : "Second";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string s_temp_temp;
        getline(cin, s_temp_temp);

        vector<string> s_temp = split(rtrim(s_temp_temp));

        vector<int> s(n);

        for (int i = 0; i < n; i++) {
            int s_item = stoi(s_temp[i]);

            s[i] = s_item;
        }

        string result = nimbleGame(s);

        fout << result << "\n";
    }

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
