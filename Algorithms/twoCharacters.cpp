#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'alternate' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */
 
// #include <algorithm>
// #include <set>
// #include <vector>

int alternate(std::string const & _str) {
    if(_str.size() == 1){
        return 0;
    }
    std::set<char> uniqueChars;
    for(auto c : _str){
            uniqueChars.emplace(c);
    }
    if(uniqueChars.size() == 1){
        return 0;
    }
    std::vector<char> possibleAlteredStr;
    possibleAlteredStr.reserve(_str.size());
    int maxSize = 0;
    int newPossibleMaxSize = 0;
    auto it = std::cbegin(uniqueChars);
    decltype(it) next;
    
    for(; it != --std::cend(uniqueChars); ++it){
        next = it;
        ++next;
        for(; next != std::cend(uniqueChars); ++next){
            for(auto c : _str){
                if(
                        c == *it
                    ||  c == *next
                ){
                    if (c == possibleAlteredStr.back()){
                        possibleAlteredStr.clear();
                        break;
                    }
                    possibleAlteredStr.emplace_back(c);
                }
            }
            newPossibleMaxSize = possibleAlteredStr.size();
            if(newPossibleMaxSize > maxSize){
                maxSize = newPossibleMaxSize;
            }
            possibleAlteredStr.clear();
        }
    }
    
    return maxSize;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string l_temp;
    getline(cin, l_temp);

    int l = stoi(ltrim(rtrim(l_temp)));

    string s;
    getline(cin, s);

    int result = alternate(s);

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
