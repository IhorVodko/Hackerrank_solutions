// problem : https://www.hackerrank.com/challenges/tutorial-intro/problem?isFullScreen=true

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'minimumNumber' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. STRING password
 */

// #include <algorithm>
// #include <unordered_map>

// Return the minimum number of characters to make the password strong
int minimumNumber(int passwordLength, std::string const & password) {
    static constexpr int kMinRequiredLength = 6;
    static constexpr int kTotalNumOfRequirements = 4;
    static std::string const kSpecialChars = "!@#$%^&*()-+";
    std::unordered_map<std::string, size_t> requirementsSatisfied;
    for(auto chr : password) 
    {
        if('a' <= chr && chr <= 'z')
        {
            ++requirementsSatisfied["lowerCase"];
        } else if('A' <= chr && chr <= 'Z') {
            ++requirementsSatisfied["upperCase"];
        } else if('0' <= chr && chr <= '9') {
            ++requirementsSatisfied["digit"];
        } else if(std::find(
                        std::cbegin(kSpecialChars)
                    ,   std::cend(kSpecialChars)
                    ,   chr) 
                != std::cend(kSpecialChars)) {
            ++requirementsSatisfied["specialChar"];
        }
    }
    return std::max(
            kMinRequiredLength - passwordLength
        ,   kTotalNumOfRequirements - static_cast<int>(requirementsSatisfied.size())
    );
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string password;
    getline(cin, password);

    int answer = minimumNumber(n, password);

    fout << answer << "\n";

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
