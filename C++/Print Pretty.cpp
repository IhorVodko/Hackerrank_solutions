//Problem: https://www.hackerrank.com/challenges/prettyprint/problem


#include <iostream>
#include <iomanip> 
using namespace std;

int main() {
	int T; cin >> T;
	cout << setiosflags(ios::uppercase);
	cout << setw(0xf) << internal;
	while(T--) {
		double A; cin >> A;
		double B; cin >> B;
		double C; cin >> C;

        std::cout << std::hex << std::showbase << std::left << std::nouppercase;
        std::cout << (long long) A << std::endl;

        std::cout << std::dec << std::setw(15) << std::right << std::setfill('_') << std::showpos << std::fixed << std::setprecision(2);
        std::cout << B << std::endl; 

        std::cout << std::scientific << std::setprecision(9) << std::uppercase << std::noshowpos;
        std::cout << C << std::endl;
	}
	return 0;

}
