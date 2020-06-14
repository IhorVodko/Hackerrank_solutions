//Problem: https://www.hackerrank.com/challenges/cpp-lower-bound/problem


#include <vector>
#include <iostream>
#include <algorithm>


int main() {

    size_t n; 
    int num;
    std::cin >> n;
    std::vector<int> v;
    for (size_t i = 0; i < n; ++i) {
        std::cin >> num;
        v.push_back(num);
    }

    size_t q;
    int val;
    std::cin >> q;
    for (size_t i = 0; i < q; ++i) {
        std::cin >> val;
        auto low = std::lower_bound(v.cbegin(), v.cend(), val);
        if ( *low == val)
            std::cout << "Yes ";
        else
            std::cout << "No ";
        std::cout << (std::distance(v.cbegin(), low) + 1) << std::endl;
    }
}
