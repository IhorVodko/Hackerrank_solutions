// problem: https://www.hackerrank.com/challenges/jesse-and-cookies/problem?isFullScreen=true


#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'cookies' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. INTEGER_ARRAY A
 */

#include <functional>
#include <queue>
#include <vector>

int cookies(
        int const & _minSweetness 
    ,   std::vector<int> const & _sweetnesses
){
    using namespace std;
    using Sweetness_t = remove_reference<
        decltype(_sweetnesses)>::type::value_type;
    auto comp = greater<Sweetness_t>();
    auto sweetnesses = priority_queue<
        Sweetness_t, vector<Sweetness_t>, decltype(comp)>(
            begin(_sweetnesses), end(_sweetnesses), comp);
    Sweetness_t x = 0;
    Sweetness_t y = 0;
    auto minSteps = 0;
    while(  sweetnesses.size() >= 2 &&
            sweetnesses.top() < _minSweetness){
        ++minSteps;
        x = sweetnesses.top();
        sweetnesses.pop();
        y = sweetnesses.top();
        sweetnesses.pop();
        sweetnesses.emplace(x + 2 * y);
    }
    return sweetnesses.top() >= _minSweetness ?
        minSteps : -1;           
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string A_temp_temp;
    getline(cin, A_temp_temp);

    vector<string> A_temp = split(rtrim(A_temp_temp));

    vector<int> A(n);

    for (int i = 0; i < n; i++) {
        int A_item = stoi(A_temp[i]);

        A[i] = A_item;
    }

    int result = cookies(k, A);

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
