//Problem: https://www.hackerrank.com/challenges/deque-stl/problem


#include <iostream>
#include <deque> 
using namespace std;

void printKMax(int arr[], int n, int k){
	
    std::deque<int> d;

    for (int i=0; i<k; ++i) {
        while (!d.empty() && arr[d.back()] <= arr[i]) {
            d.pop_back();
        }
        d.push_back(i);
    }
    for (int i=k; i<n; ++i) {
        std::cout << arr[d.front()] << ' ';
        if ((i - d.front()) == k) {
            d.pop_front();
        }
        while (!d.empty() && arr[d.back()] <= arr[i]) {
            d.pop_back();
        }
        d.push_back(i);
    }
    std::cout << arr[d.front()] << '\n';
}

int main(){
  
	int t;
	cin >> t;
	while(t>0) {
		int n,k;
    	cin >> n >> k;
    	int i;
    	int arr[n];
    	for(i=0;i<n;i++)
      		cin >> arr[i];
    	printKMax(arr, n, k);
    	t--;
  	}
  	return 0;
}
