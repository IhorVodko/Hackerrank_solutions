//Problem: https://www.hackerrank.com/challenges/virtual-functions/problem


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#include <array>
#include <string>
#include <numeric>

class Person {
    protected:
        std::string name;
        int age;
        virtual std::string toString() const {
            return name + ' ' + std::to_string(age);
        }
    ~Person() {}
    public:
        virtual void getdata() {
            std::cin >> name >> age;
        }
        virtual void putdata(std::ostream &out = std::cout) const {
            out << toString() << std::endl;
        }
};

class Professor: public Person {
        const int cur_id;
        int publications;
    protected:
        std::string toString() const override {
            return Person::toString()
                + ' ' + std::to_string(publications)
                + ' ' + std::to_string(cur_id);
        }
    public:
        static int id_count;
        Professor() : cur_id{++id_count} {}
        void getdata() override {
            Person::getdata();
            std::cin >> publications;
        }
};

class Student final: public Person {
        const int cur_id;
        std::array<int, 6> marks;
    protected:
        std::string toString() const override {
            return Person::toString()
                + ' ' + std::to_string(
                    std::accumulate(marks.begin(), marks.end(), 0))
                + ' ' + std::to_string(cur_id);        
        }
    public:
        static int id_count;
        Student(): cur_id{++id_count} {}
        void getdata() override {
            Person::getdata();
            for (auto &mark: marks) {
                std::cin >> mark;
            }
        }
};

int Professor::id_count = 0;
int Student::id_count = 0;

int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
