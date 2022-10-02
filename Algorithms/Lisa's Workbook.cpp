//problem : https://www.hackerrank.com/challenges/lisa-workbook/


#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'workbook' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER k
 *  3. INTEGER_ARRAY arr
 */

int workbook(int _n, int _k, vector<int> const & _arr) {

    int 
            pageNumber = 0
        ,   problemNumber = 1
        ,   result = 0
    ;

    for( auto numOfProblems : _arr )
    {
        if( numOfProblems < pageNumber )
        {
            pageNumber 
                +=      !( numOfProblems % _k )
                    ?   numOfProblems / _k
                    :   numOfProblems / _k + 1
            ;
            
            continue;
        }
        
        problemNumber = 1;
        ++pageNumber;
        
        while( numOfProblems > 0 )
        {
            --numOfProblems;
            
            if( problemNumber == pageNumber )
            {
                ++result;
            }
            
            if( 
                    !( problemNumber % _k )
                &&  numOfProblems
            )
            {
                ++pageNumber;
            }
            
            ++problemNumber;
        }
    }

    return result;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = workbook(n, k, arr);

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
