//Problem: https://github.com/IhorVodko/Hackerrank_solutions/edit/master/C++/Cpp%20exception%20handling.cpp


#include <iostream>
#include <stdexcept>

using namespace std;

int largest_proper_divisor(int n) {
    if (n == 0) {
        throw invalid_argument("largest proper divisor is not defined for n=0");
    }
    if (n == 1) {
        throw invalid_argument("largest proper divisor is not defined for n=1");
    }
    for (int i = n/2; i >= 1; --i) {
        if (n % i == 0) {
            return i;
        }
    }
    return -1; // will never happen
}

void process_input(int n) {
    // int d;
    try {
        int d = largest_proper_divisor(n);
        std::cout << "result=" << d << std::endl;
    }
    catch (const invalid_argument &err) {
        std::cout << err.what() << '\n';
    }
    catch (...) {
    }
    std::cout << "returning control flow to caller" << '\n';
}


int main() {
    int n;
    cin >> n;
    process_input(n);
    return 0;
}
