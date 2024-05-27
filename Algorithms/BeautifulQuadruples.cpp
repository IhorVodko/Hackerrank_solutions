// problem: https://www.hackerrank.com/challenges/xor-quadruples/problem?isFullScreen=true


#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

/*
 * Complete the beautifulQuadruples function below.
 */

// #include <algorithm>
// #include <cmath>
// #include <vector>
// #include <numeric>

// int beautifulQuadruples(
size_t beautifulQuadruples(
    int const _num1, 
    int const _num2, 
    int const _num3, 
    int const _num4
){
    using namespace  std;
    using vec = vector<size_t>;
    auto nums{vector<int>{_num1, _num2, _num3, _num4}};
    sort(begin(nums), end(nums));
    auto pairNum1Num2Counts{vec(nums.at(2) + 1, 0)};
    iota(begin(pairNum1Num2Counts), begin(pairNum1Num2Counts) + nums.at(0), 0);
    fill(begin(pairNum1Num2Counts) + nums.at(0), begin(pairNum1Num2Counts) +
        nums.at(1) + 1, nums.at(0));
    partial_sum(begin(pairNum1Num2Counts), end(pairNum1Num2Counts),
        begin(pairNum1Num2Counts));
    auto xorNum2Counts{vector<vec>(nums.at(2) + 1,
        vec(static_cast<size_t>(pow(2, ceil(log2f(nums.at(3) + 1)))) + 1, 0))};
    for(auto num1{1}; num1 <= nums.at(0); ++num1){
        for(auto num2{num1}; num2 <= nums.at(1); ++num2){
            ++xorNum2Counts.at(num2).at(num1 ^ num2);
        }
    }
    transform(begin(xorNum2Counts) + 1, end(xorNum2Counts),
        begin(xorNum2Counts), begin(xorNum2Counts) + 1,
        [&](auto & xorCountsThis, auto & xorCountsPrev){
            transform(begin(xorCountsThis), end(xorCountsThis),
                begin(xorCountsPrev), begin(xorCountsThis),
                [&](auto xorCountThis, auto xorCountPrev){
                    return xorCountThis + xorCountPrev;
                });
            return xorCountsThis;
        });
    size_t pairsXorZeroCount = 0;
    for(auto num3{1}; num3 <= nums.at(2); ++num3){
        for(auto num4{num3}; num4 <= nums.at(3); ++num4){
            pairsXorZeroCount += pairNum1Num2Counts.at(num3) -
                xorNum2Counts.at(num3).at(num3 ^ num4);
        }
    }
    return pairsXorZeroCount;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string abcd_temp;
    getline(cin, abcd_temp);

    vector<string> abcd = split_string(abcd_temp);

    int a = stoi(abcd[0]);

    int b = stoi(abcd[1]);

    int c = stoi(abcd[2]);

    int d = stoi(abcd[3]);

    // int result = beautifulQuadruples(a, b, c, d);
    size_t result = beautifulQuadruples(a, b, c, d);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
