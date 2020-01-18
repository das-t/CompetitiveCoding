#include <iostream>
#include <map>
using  namespace std;
#define ll long long int

// You are given a linear equation y = mx + c, and an array A of n elements. Count
// the number of ordered pairs (i,j) where i!=j, such that point (Ai, Aj) satisfies
// the given linear equation.

map<double,ll> mapAns;

int main(){
    ll elements;
    cin>>elements;
    double m,c;
    cin>>m>>c;
    double* array = new double[elements];
    for(ll i=0;i<elements;i++){
        cin>>array[i];
        mapAns[array[i]]++;
    }
    ll count = 0;
    for(ll i=0;i<elements;i++){
        double y = m*array[i]+c;
        if(mapAns.find(y)!=mapAns.end() && y!=array[i])
            count += mapAns[y];
        else if(mapAns.find(y)!=mapAns.end())
            count += mapAns[y]-1;
    }
    cout<<count<<endl;
    delete[] array;
    mapAns.clear();
}