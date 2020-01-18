#include <iostream>
#include <queue>
#define ll long long int
using namespace std;

// Dean of MAIT is going to visit Hostels of MAIT. As you know that he 
// is a very busy person so he decided to visit only first "K" nearest
// Hostels. Hostels are situated in 2D plane. You are given the coordinates
// of hostels and you have to answer the Rocket distance of Kth nearest
// hostel from origin (Dean's place)

int main(){
    ll queries,kth;
    cin>>queries>>kth;
    priority_queue<ll> que;
    while(queries-->0){
        ll option;
        cin>>option;
        if(option==1){
            ll x,y;
            cin>>x>>y;
            que.push(x*x+y*y);
            if(que.size()>kth)
                que.pop();
        } else 
            cout<<que.top()<<endl;
    }
}