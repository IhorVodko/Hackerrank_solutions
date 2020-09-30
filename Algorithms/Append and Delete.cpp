//problem:  https://www.hackerrank.com/challenges/append-and-delete/problem


#include <bits/stdc++.h>

using namespace std;

// Complete the appendAndDelete function below.
string appendAndDelete(string s, string t, int k) {

    int i = 0;
    while (t[i] == s[i]) {
        i++;
    }

    int m=0, n=0;
    m = s.length() - i;
    n = t.length() - i;

    int min_ops_required = m + n;

    int finall_ops_reaching_k = min_ops_required;
    while (finall_ops_reaching_k < k) {
        if (i-- > 0) {
            finall_ops_reaching_k += 2; 
        }
        else {
            finall_ops_reaching_k++;
        }
    }
    
    string result;
    if (finall_ops_reaching_k == k) { 
        result = "Yes";
    } else {
        result = "No";
    }

    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string t;
    getline(cin, t);

    int k;
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string result = appendAndDelete(s, t, k);

    fout << result << "\n";

    fout.close();

    return 0;
}
