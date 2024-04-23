// problem: https://www.hackerrank.com/challenges/absolute-permutation/problem?isFullScreen=true


#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'absolutePermutation' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER k
 */

// #include <numeric>
// #include <vector>
// #include <type_traits>

std::vector<int> absolutePermutation(
    int const & _numsLimit,
    int const & _diff
){
    using namespace std;
    using num_t = remove_const<remove_reference<decltype(_numsLimit)>
        ::type>::type;
    if(_diff == 0){
        auto result = std::vector<num_t>(_numsLimit);
        iota(begin(result), end(result), 1);
        return result;
    }
    if(_numsLimit % (_diff * 2) != 0){
        return {-1};
    }
    auto result = std::vector<num_t>(_numsLimit);
    iota(begin(result), end(result), 1);
    auto window = _diff * 2;
    for(auto idx = 0; idx != result.size(); idx += window){
        for(auto idx1 = idx, idx2 = idx1 + _diff; idx2 != idx + window;
            ++idx1, ++idx2
        ){
            swap(result.at(idx1), result.at(idx2));
        }
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int n = stoi(first_multiple_input[0]);

        int k = stoi(first_multiple_input[1]);

        vector<int> result = absolutePermutation(n, k);

        for (size_t i = 0; i < result.size(); i++) {
            fout << result[i];

            if (i != result.size() - 1) {
                fout << " ";
            }
        }

        fout << "\n";
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
