//Problem: https://www.hackerrank.com/challenges/classes-objects/problem


#include <cmath>... //hidden code

class Student {
private:
    int scores[5];
    int sum;
public:
    Student()
        : sum(0) {}
    int calculateTotalScore() {return sum;}
    void input() {
        for (int i{}; i < 5; ++i) {
            cin >> scores[i];   
            sum += scores[i];
        }
    }
};

int main() {... //hidden code
