//problem : https://www.hackerrank.com/challenges/minimum-distances/problem

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'minimumDistances' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY a as parameter.
 */
 
int minimumDistances(const vector<int>& a) 
{
    
    typedef multimap<int, int> M;
    multimap<int, int> numIndxs;
    int num = 0;
    for (size_t i = 0; i < a.size(); ++i)
    {
        numIndxs.insert(pair<int, int>(a.at(i), i));
    }
    vector<int> IndxsForKey;
    int minD = INT_MAX;
    for (auto el: numIndxs)
    {
        pair<M::iterator, M::iterator> rngEq = numIndxs.equal_range(el.first);
        transform(rngEq.first, rngEq.second, back_inserter(IndxsForKey),
            [](pair<int, int> p){ return p.second; });
        if (IndxsForKey.size() >= 2)
        {
            for(size_t i = 0; i < (IndxsForKey.size() - 1); ++i)
            {
                minD = min((IndxsForKey.at(i+1) - IndxsForKey.at(i)), minD); 
                if (minD == 1)
                {
                    return minD;
                }
            }
        }
        IndxsForKey.clear();
    }
 
    return INT_MAX == minD ? -1 : minD;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split(rtrim(a_temp_temp));

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        int a_item = stoi(a_temp[i]);

        a[i] = a_item;
    }

    int result = minimumDistances(a);

    fout << result << "\n";

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
