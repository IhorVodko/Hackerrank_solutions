//Problem: https://www.hackerrank.com/challenges/box-it/problem


#include<bits/stdc++.h>
using namespace std;

class Box {
  private:

    int l = 0;
    int b = 0;
    int h = 0;

  public:

    int getLength() const {
        return l;
    }
    int getBreadth() const {
        return b;
    }
    int getHeight() const {
        return h;
    }
    long long CalculateVolume () {
        return (long long)l*b*h;
    }

    Box() {
    }
    
    Box(int length, int breadth, int height) {

        l=length;
        b=breadth;
        h=height;
    }

    Box(const Box &B) {

        l = B.getLength();
        b = B.getBreadth();
        h = B.getHeight();
    }

    ~Box() {
    }

    bool operator<(const Box &B) {

        int ll = B.getLength();
        int bb = B.getBreadth();
        int hh = B.getHeight();

        if(l < ll || (b < bb && l==ll) || (h < hh && b==bb && l==ll))

            return true;
        else

            return false;
    }
};

ostream &operator<<(ostream &out, Box B) {

    int l = B.getLength();
    int b = B.getBreadth();
    int h = B.getHeight();

    return out<<l<<' '<<b<<' '<<h;
}
