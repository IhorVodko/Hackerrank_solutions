// problem : https://www.hackerrank.com/challenges/separate-the-numbers/problem?isFullScreen=true


#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'separateNumbers' function below.
 *
 * The function accepts STRING s as parameter.
 */

// #include <string>
// #include <cmath>

std::string calculate(
        std::string const & _str
    ,   size_t const & _strSize
    ,   size_t & _thisLen
){
    long long int thisNum = 0;
    long long int nextNum = 0;
    long long int numForYes = 0;
    size_t thisBeg = 0;
    size_t nextBeg = thisBeg + _thisLen;
    size_t nextLen = 1;
    bool isFirstNum = true;
    while(nextBeg + nextLen <= _strSize){
        thisNum = std::stoll(_str.substr(thisBeg, _thisLen));
        nextNum = std::stoll(_str.substr(nextBeg, nextLen));
        if((thisNum / pow(10, _thisLen - 1)) == 0) {
            return "NOZERO";
        }
        if(_thisLen > _strSize / 2 + 1){
            return "NO";
        }
        if(thisNum >= nextNum){
            if(nextBeg + nextLen == _strSize){
                return "NO";
            }
            ++nextLen;
        }else{
            if(thisNum + 1 == nextNum){
                if(isFirstNum){
                    numForYes = thisNum;
                    isFirstNum = false;
                }
                if(nextBeg + nextLen == _strSize) {
                    return "YES " + std::to_string(numForYes);
                }
                thisBeg = nextBeg;
                nextBeg = thisBeg + nextLen;
                _thisLen = nextLen;
                nextLen = 1;
            }else{
                if(thisBeg + _thisLen == _strSize - 1){
                    return "NO";
                }
                ++_thisLen;
                nextBeg = thisBeg + _thisLen;
                nextLen = 1;  
            }
        }            
    }
    return "NO";
}

void separateNumbers(std::string const & _str){
    auto const strSize = _str.size();
    if(strSize == 1){
        std::cout << "NO\n";
        return;
    }
    std::string answr;
    size_t thisLen = 0;
    size_t oldThisLen = 0;
    do{
        oldThisLen = ++thisLen;
        answr = ::calculate(_str, strSize, thisLen);
        thisLen = oldThisLen;
    }while(
            thisLen < strSize / 2 - 1 
        &&  answr == "NO"
        &&  answr != "NOZERO"
    );
    std::cout << (answr == "NOZERO" ? "NO" : answr) << '\n';
}

int main()
{
    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        separateNumbers(s);
    }

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
