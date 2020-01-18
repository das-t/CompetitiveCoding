#include <iostream>
#include <map>
#define MAX 300005
#define ll long long int
using namespace std;

map<string,ll> priceMap;
map<string,ll> mapOccur;

void updateValue(ll index,ll value,ll* array,ll elements){
    while(index<elements){
        array[index] += value;
        index += (index & (-index));
    }
}

ll query(ll index,ll * array){
    ll totalSum = 0;
    while(index>0){
        totalSum += array[index];
        index -= (index & (-index));
    }
    return totalSum;
}
void printArray(ll* array,ll elements){
    for(ll i=0;i<elements;i++)
        cout<<array[i]<<" ";
    cout<<endl;
}

int main(){
    ll elements;
    cin>>elements;
    ll* array = new ll[MAX];
    for(ll i=0;i<MAX;i++)
        array[i] = 0;
    while(elements-->0){
        string item;
        ll price;
        cin>>item>>price;
        priceMap[item] = price;
    }
    ll queries;
    cin>>queries;
    ll totalElements = 0;
    while(queries-->0){
        char option;
        cin>>option;
        if(option=='+'){
            string item;
            cin>>item;
            ll price = priceMap[item];
            updateValue(1,1,array,MAX-1);
            updateValue(price+1,-1,array,MAX-1);
            mapOccur[item]++;
        } else if(option=='-'){
            string item;
            cin>>item;
            if(mapOccur[item]>0){
            ll price = priceMap[item];
            updateValue(1,-1,array,MAX-1);
            updateValue(price+1,1,array,MAX-1);
            mapOccur[item]--;
            }
        } else {
            ll minPrice;
            cin>>minPrice;
            cout<<query(minPrice+1,array)<<endl;
        }
    }
    delete[] array;
}