//Problem: https://www.hackerrank.com/challenges/find-digits/problem


#include <bits/stdc++.h>

using namespace std;

// Complete the findDigits function below.
int findDigits(const int &n) {

    int num, count{0};
    num = n;
    while(num%10 != num) {

        int remainder;
        remainder = num%10;
        num = num/10;
        if (remainder == 0)
            continue;
        if (n%remainder == 0)
            count++;
    }
    if (num != 0 && n%num==0)
        count++;

    return count;    

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int result = findDigits(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
