//Problem: https://www.hackerrank.com/challenges/attending-workshops/problem


#include<bits/stdc++.h>

using namespace std;

struct Workshops {
    int start_time;
    int duration;
    int end_time; 
};

struct Available_Workshops {
    int n;
    vector <Workshops> vec_w;
};

Available_Workshops *initialize(int *start_time, int *duration, int n) {
    Available_Workshops *paw = new Available_Workshops;
    Workshops ws;
        paw->n = n;
    for (int i=0; i<n; ++i) {
        ws.start_time = start_time[i];
        ws.duration = duration[i];
        ws.end_time = start_time[i]+duration[i];
        paw->vec_w.push_back(ws);   
    }
      return paw;    
}

bool compare(Workshops w1, Workshops w2) { 
    return (w1.end_time < w2.end_time); 
}

int CalculateMaxWorkshops(Available_Workshops *ptr) {
    sort(ptr->vec_w.begin(),ptr->vec_w.end(),compare); 
    int prev_end_time = -1;
    int max_workshops = 0;
    for (int i=0; i<ptr->n; ++i) {
        if (ptr->vec_w.at(i).start_time >= prev_end_time) {
            prev_end_time = ptr->vec_w.at(i).end_time;
            ++max_workshops;
        }
    }
    return max_workshops;
}


int main(int argc, char *argv[]) {
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for(int i=0; i < n; i++){
        cin >> start_time[i];
    }
    for(int i = 0; i < n; i++){
        cin >> duration[i];
    }

    Available_Workshops * ptr;
    ptr = initialize(start_time,duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}
