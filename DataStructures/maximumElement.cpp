// problem: https://www.hackerrank.com/challenges/maximum-element/problem?isFullScreen=true


#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'getMax' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts STRING_ARRAY operations as parameter.
 */

// #include <algorithm>
// #include <string>
// #include <stack>
// #include <vector>

vector<int> getMax(vector<string> const & _operations){
    using namespace std;
    auto command = 0;
    auto stck = stack<int>();
    auto result = vector<int>();
    for(auto op : _operations){
        command = op[0];
        switch (command){
            case '1':{
                stck.emplace(max(stck.empty() ?
                    0 : stck.top(),stoi(op.substr(2))));
                break;
            }case '2':{
                stck.pop();
                break;
            }case '3':{
                result.emplace_back(stck.top());
                break;
            }default:{
                assert(false && "not known command");
            }
        }
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<string> ops(n);

    for (int i = 0; i < n; i++) {
        string ops_item;
        getline(cin, ops_item);

        ops[i] = ops_item;
    }

    vector<int> res = getMax(ops);

    for (size_t i = 0; i < res.size(); i++) {
        fout << res[i];

        if (i != res.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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
