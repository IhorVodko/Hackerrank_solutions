//Problem: https://www.hackerrank.com/challenges/cpp-sets/problem


#include <iostream>
#include <set>
#include <algorithm>

int main() {
    
    std::set<int> s;
    size_t q;

    std::cin >> q;

    int x, y;
    for (size_t i = 0; i < q; ++i) {
        std::cin >> y >> x;
        if (y == 1)
            s.insert(x);
        else if (y == 2) 
            s.erase(x);
        else 
            std::cout << (s.find(x) != s.end() ?  "Yes" : "No") << std::endl;            
    }
}

