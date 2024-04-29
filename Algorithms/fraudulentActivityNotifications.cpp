// problem: https://www.hackerrank.com/challenges/fraudulent-activity-notifications/problem?isFullScreen=true


#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'activityNotifications' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY expenditure
 *  2. INTEGER d
 */

// #include <vector>

int activityNotifications(
        std::vector<int> const & _sumsSpent
    ,   int const & _windowSz
){
    auto const & szSpent = _sumsSpent.size();
    auto const windowSz = static_cast<size_t>(_windowSz);
    if(szSpent <= windowSz){
        return 0;
    }
    static constexpr size_t frequenciesSz = 201;
    auto frequencies = std::vector<size_t>(frequenciesSz, 0);
    for(auto sumSpent = std::cbegin(_sumsSpent);
        sumSpent < std::cbegin(_sumsSpent) + windowSz; ++sumSpent)
    {
        ++frequencies.at(*sumSpent);
    }
    auto middlePos = windowSz / 2 + 1;
    auto shift = windowSz % 2 == 0 ? 1 : 0;
    size_t frequenciesAccum = 0;
    size_t notifs = 0;
    size_t medianSum = 0;
    for(auto sumSpentFirst = std::cbegin(_sumsSpent), 
        sumSpentLast = sumSpentFirst + windowSz;
        sumSpentLast < std::cend(_sumsSpent);
        ++sumSpentFirst, ++sumSpentLast
    ){
        medianSum = 0;
        frequenciesAccum = 0;
        for(auto sumSpent = 0; sumSpent < frequenciesSz; ++sumSpent){
            frequenciesAccum += frequencies.at(sumSpent);
            if(medianSum == 0 && frequenciesAccum >= middlePos - shift){
                medianSum += sumSpent;
            }
            if(frequenciesAccum >= middlePos){
                medianSum += sumSpent;
                if(medianSum <= static_cast<size_t>(*sumSpentLast)){
                    ++notifs;
                }
                break;
            } 
        }
        frequencies.at(*sumSpentFirst) =
            frequencies.at(*sumSpentFirst) == 0 ?
                0 : frequencies.at(*sumSpentFirst) - 1;
        ++frequencies.at(*sumSpentLast);
    }
    return static_cast<int>(notifs);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int d = stoi(first_multiple_input[1]);

    string expenditure_temp_temp;
    getline(cin, expenditure_temp_temp);

    vector<string> expenditure_temp = split(rtrim(expenditure_temp_temp));

    vector<int> expenditure(n);

    for (int i = 0; i < n; i++) {
        int expenditure_item = stoi(expenditure_temp[i]);

        expenditure[i] = expenditure_item;
    }

    int result = activityNotifications(expenditure, d);

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
