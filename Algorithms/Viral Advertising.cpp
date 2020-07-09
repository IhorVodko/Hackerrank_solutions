//Problem: https://www.hackerrank.com/challenges/strange-advertising/problem


#include <bits/stdc++.h>

using namespace std;

// Complete the viralAdvertising function below.
int viralAdvertising(const int &n) {

    int people = 5, sum = 0, people_liked = 0;

    for(int day = 1; day <= n; ++day) {

        people_liked = people/2;
        sum += people_liked;
        people = people_liked * 3; 
    }
    return sum;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = viralAdvertising(n);

    // std::cout << result << '\n';
    fout << result << "\n";

    fout.close();

    return 0;
}


