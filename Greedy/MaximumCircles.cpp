#include <iostream>
#include <algorithm>
#define ll long long int
using namespace std;

// There are n circles arranged on x-y plane. All of them have their centers
// on x-axis. You have to remove some of them, such that no two circles are
// overlapping after that. Find the minimum number of circles that need to be removed.

struct cmpr{
    bool operator()(pair<ll,ll> left,pair<ll,ll> right){
        return left.second<right.second;
    }
}compare;

ll nonOverlappedActivity(pair<ll,ll>* array,ll elements){
    if(elements<=1)
        return elements;
    sort(array,array+elements,compare);
    ll activity = 1;
    ll currentFinishPoll = array[0].second;
    for(ll i=1;i<elements;i++)
        if(currentFinishPoll <= array[i].first){
            currentFinishPoll = array[i].second;
            activity++;
        }
    return activity;
}

int main(){
    ll elements;
    cin>>elements;
    pair<ll,ll>* array = new pair<ll,ll>[elements];
    for(ll i=0;i<elements;i++){
        ll center,radius;
        cin>>center>>radius;
        array[i].first = center-radius;
        array[i].second = center+radius;
    }
    cout<<(elements-nonOverlappedActivity(array,elements))<<endl;
    delete[] array;
}