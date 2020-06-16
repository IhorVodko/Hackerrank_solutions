//Problem:  https://github.com/IhorVodko/Hackerrank_solutions/new/master/C%2B%2B


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Triangle{
	public:
		void triangle(){
			cout<<"I am a triangle\n";
		}
};

class Isosceles : public Triangle{
  	public:
  		void isosceles(){
    		cout<<"I am an isosceles triangle\n";
  		}
};

class Equilateral: public Isosceles {
    public:
        void equilateral() {
            std::cout << "I am an equilateral triangle" << std::endl;
        }
};

//Write your code here.

int main(){
  
    Equilateral eqr;
    eqr.equilateral();
    eqr.isosceles();
    eqr.triangle();
    return 0;
}
