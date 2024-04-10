// problem: https://www.hackerrank.com/challenges/the-time-in-words/problem?isFullScreen=true


#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'timeInWords' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. INTEGER h
 *  2. INTEGER m
 */

// #include <string>

std::string numToWords(int const & _num){
    using namespace std;
    auto d1 = _num / 10;
    auto d2 = _num % 10;
    auto time = string();
    switch(d1){
        case 0:{
            break;   
        }case 1:{
            switch(d2){
                case 0:{
                    return "ten";
                }case 1:{
                    return "eleven";
                }case 2:{
                    return "twelve";
                }case 3:{
                    return "thirteen";
                }case 4:{
                    return "fourteen";
                }case 5:{
                    return "fifteen";
                }case 6:{
                    return "sixteen";
                }case 7:{
                    return "seventeen";
                }case 8:{
                    return "eighteen";
                }case 9:{
                    return "nineteen";
                }
            }
        }case 2:{
            time += "twenty";
            break;
        }case 3:{
            time += "thirty";
            break;
        }case 4:{
            time += "fourty";
            break;
        }case 5:{
            time += "fifty";
            break;
        }case 6:{
            time += "sixty";
            break;
        }case 7:{
            time += "seventy";
            break;
        }case 8:{
            time += "eighty";
            break;
        }case 9:{
            time += "ninety";
            break;
        }default:{
            time += "unknown d1!";
        }
    }
    if(d1 != 0){
        time += " ";
    }
    switch(d2){
        case 0:{
            break;
        }case 1:{
            return time + "one";
        }case 2:{
            return time + "two";
        }case 3:{
            return time + "three";
        }case 4:{
            return time + "four";
        }case 5:{
            return time + "five";
        }case 6:{
            return time + "six";
        }case 7:{
            return time + "seven";
        }case 8:{
            return time + "eight";
        }case 9:{
            return time + "nine";
        }default:{
            return time += "unknown d2!";
        }
    }
    return "unknown num!";
}

std::string timeInWords(
        int const & _h
    ,   int const & _m
){
    using namespace std;
    auto time =  string();
    if(_m == 0){
        return ::numToWords(_h) + " o' clock";
    }else if((1 <= _m && _m <= 14) ||
        (16 <= _m && _m <= 29)
    ){
        return ::numToWords(_m) + 
            (_m == 1 ? " minute" : " minutes") + " past " +
            ::numToWords(_h);
    }else if(_m == 15){
        return "quarter past " + ::numToWords(_h);
    }else if(_m == 30){
        return "half past " + ::numToWords(_h);   
    }else if(_m == 45){
        return "quarter to " + ::numToWords((_h + 1) % 13);  
    }else{
        return ::numToWords(60 - _m) + " minutes to " +
            ::numToWords((_h + 1) % 13); 
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string h_temp;
    getline(cin, h_temp);

    int h = stoi(ltrim(rtrim(h_temp)));

    string m_temp;
    getline(cin, m_temp);

    int m = stoi(ltrim(rtrim(m_temp)));

    string result = timeInWords(h, m);

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
