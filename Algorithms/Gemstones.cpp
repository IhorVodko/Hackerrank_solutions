// problem : https://www.hackerrank.com/challenges/gem-stones/problem?isFullScreen=true


#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'gemstones' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING_ARRAY arr as parameter.
 */

// #include <algorithm>
// #include <string>
// #include <vector> 
// #include <unordered_map>
// #include <unordered_set>

int gemstones(std::vector<std::string> _vec) {
    std::unordered_map<char, size_t> mineralsCount;
    for(auto & rock : _vec){
        for(auto const & mineral
            : std::unordered_set(rock.cbegin(), rock.cend())){
            ++mineralsCount[mineral];
        }
    }
    auto const sz = _vec.size();
    return std::count_if(
            mineralsCount.cbegin()
        ,   mineralsCount.cend()
        ,   [&](std::pair<char, size_t> const & _x){return _x.second == sz;}
    );
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<string> arr(n);

    for (int i = 0; i < n; i++) {
        string arr_item;
        getline(cin, arr_item);

        arr[i] = arr_item;
    }

    int result = gemstones(arr);

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
