//Problem: https://www.hackerrank.com/challenges/cpp-class-template-specialization/problem


#include <iostream>
using namespace std;
enum class Fruit { apple, orange, pear };
enum class Color { red, green, orange };

template <typename T> struct Traits;

template <>
struct Traits<Fruit> {
    static const int min = static_cast<int>(Fruit::apple);
    static const int max = static_cast<int>(Fruit::pear);

    static const char *name(int index) {
        if (index < min || index > max) {
            return "unknown";
        }
        switch (static_cast<Fruit>(index)) {
            case Fruit::apple: 
                return "apple";
                break;
            case Fruit::orange:
                return "orange";
                break;
            case Fruit::pear:
                return "pear";
                break;
            default:
                return "";
        }
    }
}; 

template <>
struct Traits<Color> {
    static const int min = static_cast<int>(Color::red);
    static const int max = static_cast<int>(Color::orange);

    static const char *name(int index) {
        if (index < min || index > max) {
            return "unknown";
        }
        switch (static_cast<Color>(index)) {
            case Color::red: 
                return "red";
                break;
            case Color::green:
                return "green";
                break;
            case Color::orange:
                return "orange";
                break;
            default:
                return "";
        }
    }
}; 

int main()
{
	int t = 0; std::cin >> t;

    for (int i=0; i!=t; ++i) {
        int index1; std::cin >> index1;
        int index2; std::cin >> index2;
        cout << Traits<Color>::name(index1) << " ";
        cout << Traits<Fruit>::name(index2) << "\n";
    }
}
