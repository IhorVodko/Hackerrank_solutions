// problem: https://www.hackerrank.com/challenges/qheap1/problem?isFullScreen=true


#include <iostream>
#include <set>
#include <string>
#include <cassert>
using namespace std;


int main(){
    auto query = string();
    size_t sz = 0;
    auto num = 0;
    cin >> sz;
    auto heap = set<int>(); 
    while(sz--){
        cin >> num;
        switch(num){
            case 1:{
                cin >> num;
                heap.insert(num);
                break;
            }
            case 2:{
                cin >> num;
                heap.erase(num);
                break;   
            }
            case 3:{
                cout << *cbegin(heap) << endl;
                break;
            }
            defaul:{
                assert(false && "not known command");
            }
        }      
    }
    return 0;
}
