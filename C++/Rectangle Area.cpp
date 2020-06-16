//Problem https://www.hackerrank.com/challenges/rectangle-area/problem


#include <iostream>

using namespace std;

class Rectangle {
protected:
    int width;
    int height;
public:
    void display() const {
        std::cout << width << ' ' << height << std::endl;
    }
};

class RectangleArea: public Rectangle {
public:
    void read_input() {
        std::cin >> width >> height;
    }
    void display() const {
        std::cout << (width * height) << std::endl;
    }
};


int main()
{
    /*
     * Declare a RectangleArea object
     */
    RectangleArea r_area;
    
    /*
     * Read the width and height
     */
    r_area.read_input();
    
    /*
     * Print the width and height
     */
    r_area.Rectangle::display();
    
    /*
     * Print the area
     */
    r_area.display();
    
    return 0;
}
