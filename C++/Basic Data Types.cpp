//Problem: https://www.hackerrank.com/challenges/c-tutorial-basic-data-types/problem?h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen

#include <iostream>
#include <iomanip>
using namespace std;

int main() {

    int a {};
    long b {};
    char c {};
    float d {};
    double e {};

    cin >> a >> b >> c >> d >> e;

    cout << a << "\n" << b << "\n" << c << "\n";
    cout << fixed << setprecision(3) <<  d << "\n";
    cout << fixed << setprecision(9) << e << "\n";

    return 0;
}
