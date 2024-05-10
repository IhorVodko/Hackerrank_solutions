//problem: https://www.hackerrank.com/challenges/maximum-palindromes/problem?isFullScreen=true


#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'initialize' function below.
 *
 * The function accepts STRING s as parameter.
 */
 // This function is called once before all queries.

// #include <vector>
// #include <string>
// #include <unordered_map>

const size_t MODULO = 1'000'000'007;
auto factorials = std::vector<size_t>();
auto modularMultiplicativeInverses = std::vector<size_t>();
auto counts = std::vector<std::unordered_map<char, size_t>>();

size_t findMdularMultiplicativeInverse(
    size_t const & _inverseOfThisNum,
    size_t const _power
){
    if(_power == 0){
        return 1;
    }
    auto  temp = 
        findMdularMultiplicativeInverse(_inverseOfThisNum, _power / 2) %
             MODULO;
    temp = (temp * temp) % MODULO;
    return  ((_power % 2) == 0 ? temp : _inverseOfThisNum * temp) %
        MODULO;
}

void initialize(
    std::string const & _str
){
    factorials.resize(_str.size() / 2 + 1, 1);
    modularMultiplicativeInverses = factorials;
    counts.resize(_str.size() + 1);
    for(size_t indx = 2; indx != factorials.size(); ++indx){
        factorials.at(indx) = (indx * factorials.at(indx - 1)) % MODULO;
        modularMultiplicativeInverses.at(indx) = 
            findMdularMultiplicativeInverse(factorials.at(indx),
                MODULO - 2);
    }
    for(size_t indx = 0; indx < _str.size(); ++indx){
        counts.at(indx + 1) = counts.at(indx);
        ++counts.at(indx + 1)[_str.at(indx)];
    }
}

/*
 * Complete the 'answerQuery' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER l
 *  2. INTEGER r
 */
// Return the answer for this query modulo 1000000007.

int answerQuery(
    int const & _begin,
    int const & _end
){
    size_t maxLenthHalf = 0;
    size_t middleChar = 0;
    size_t denominator = 1;
    size_t countCurrent = 0;
    for(auto const & [chr, count]: counts.at(_end)){
        countCurrent = count - counts.at(_begin - 1)[chr];
        if(countCurrent >= 2){
            denominator = (denominator * 
                modularMultiplicativeInverses.at(countCurrent / 2)) %
                    MODULO;
            maxLenthHalf += countCurrent / 2;
        }
        if(countCurrent % 2 == 1){
            ++middleChar;
        }
    }
    return (((factorials.at(maxLenthHalf) * denominator) % MODULO) *
        (middleChar == 0 ? 1 : middleChar)) % MODULO;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);
    
    initialize(s);

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int l = stoi(first_multiple_input[0]);

        int r = stoi(first_multiple_input[1]);

        int result = answerQuery(l, r);

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
