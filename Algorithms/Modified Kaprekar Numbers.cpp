#problem: https://www.hackerrank.com/challenges/kaprekar-numbers/problem

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'kaprekarNumbers' function below.
 *
 * The function accepts following parameters:
 *  1. INTEGER p
 *  2. INTEGER q
 */

void kaprekarNumbers(int p, int q) 
{   
    int count = 0;
    for (long i = p; i <= q; ++i)
    {   
        int c = 0; 
        long dec = i, toPow = 1;
        while (dec != 0)
        {
            dec /= 10;
            ++c;
        }
        while (c--) { toPow *= 10;}
        long Sq = i*i; 
        if (i == (Sq / toPow) +  (Sq % toPow))
        {
            cout << i << " ";
            count = 1;
        }
    }
    cout << (count == 0 ? "INVALID RANGE" : "");
}

int main()
{
    string p_temp;
    getline(cin, p_temp);

    int p = stoi(ltrim(rtrim(p_temp)));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    kaprekarNumbers(p, q);

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
