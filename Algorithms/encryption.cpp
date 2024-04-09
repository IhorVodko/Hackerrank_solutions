// problem: https://www.hackerrank.com/challenges/encryption/problem?isFullScreen=true


#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'encryption' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

// #include <algorithm>
// #include <cmath>
// #include <string>

std::string encryption(std::string & _plainText) {
    using namespace std;
    _plainText.erase(
        remove(begin(_plainText),end(_plainText), ' '),
            end(_plainText));
    auto sqrtLength = sqrt(_plainText.size());
    auto cols =  static_cast<size_t>(ceil(sqrtLength));
    auto cipherText = string();
    cipherText.reserve(_plainText.size() + cols);
    for(auto col = 0; col < cols; ++col){
        for(auto idx = col; idx < _plainText.size();
            idx += cols
        ){
            cipherText += _plainText.at(idx);
        }
        cipherText += ' ';
    }
    return cipherText.erase(cipherText.size() - 1);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = encryption(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
