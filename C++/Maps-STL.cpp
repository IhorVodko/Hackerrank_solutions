//Problem: https://github.com/IhorVodko/Hackerrank_solutions/edit/master/C++/Maps-STL.cpp


#include <iostream>
#include <algorithm>
#include <map>
#include <string>


int main() {
    
    std::map<std::string, int> m;
    size_t q;
    std::cin >> q;
    int type, mark;
    std::string name;

    for (size_t i = 0; i < q; ++i) {
        std::cin >> type >> name;
        switch(type) {
            case 1:
                std::cin >> mark;
                m[name] += mark;
                break;                
            case 2: 
                m.erase(name);
                break;
            case 3:
                std::cout << m[name] << std::endl; 
                break;
        }
    }

}
