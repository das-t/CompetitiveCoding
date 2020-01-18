#include <iostream>
#include <vector>
#include <queue>
#define MAX 10005
using namespace std;

vector<long long int> list;

void calcUgly(int elements){
    priority_queue<long long int, vector<long long int>, greater<long long int>> pq;
    pq.push(1);
    pq.push(2);
    pq.push(3);
    pq.push(5);
    while(elements-->0){
        long long int minValue = pq.top();
        while(minValue == pq.top())
            pq.pop();
        list.push_back(minValue);
        pq.push(minValue*2);
        pq.push(minValue*3);
        pq.push(minValue*5);
    }
}

int main(){
    calcUgly(MAX);
    int testCases;
    cin>>testCases;
    while(testCases-->0){
        int index;
        cin>>index;
        cout<<list.at(index-1)<<endl;
    }
}