#include <iostream>
#include <algorithm>
#include <map>
#define ll long long int
#define MOD 1000000007
using namespace std;

map<ll,ll,greater<ll>> bombMap;
map<ll,ll> locationMap;

ll getTotalMod(ll* array,ll elements){
    ll totalSUm = 0;
    sort(array,array+elements);
    for(ll i=0;i<elements;i++){
        locationMap.insert({array[i],i});
        totalSUm += i*array[i] - (elements-i-1)*array[i];
        cout<<"for index:"<<i<<" totaSum:"<<totalSUm<<endl;
    }
    return totalSUm;
}

int main(){
    int testCases;
    cin>>testCases;
    while(testCases-->0){
        ll elements;
        cin>>elements;
        ll* coordinate = new ll[elements];
        ll* price = new ll[elements];
        for(ll i=0;i<elements;i++)
            cin>>coordinate[i];
        for(ll i=0;i<elements;i++)
            cin>>price[i];
        for(ll i=0;i<elements;i++)
            bombMap.insert({price[i],coordinate[i]});
        sort(price,price+elements);
        sort(coordinate,price+elements);
        // ll totalMod = getTotalMod(coordinate,elements);
        ll * preprocessedCoordinates = new ll [elements+1];
        for(ll i=0;i<=elements;i++){
            if(i==0)
                preprocessedCoordinates[i] = coordinate[i];
            else if(i==elements)
                preprocessedCoordinates[i] = preprocessedCoordinates[i-1];
            else
                preprocessedCoordinates[i]
        }
        ll totalCost = 0;
        for(map<ll,ll>::iterator itr=bombMap.begin();itr!=bombMap.end();itr++){
            ll bomb = itr->first;
            ll location = itr->second;
            ll index = (locationMap.find(location))->second;
            cout<<"before totalCost:"<<totalCost<<" bomb:"<<bomb<<"totalMod:"<<totalMod<<endl;
            ll currentCost = 
            totalCost += bomb*currentCost;
            totalMod -= index*price[index] + (elements-index-1)*price[index];
            cout<<"after totalCost:"<<totalCost<<" totalMod:"<<totalMod<<endl;
        }
        cout<<totalCost<<endl;
        delete[] coordinate;
        delete[] price;
        bombMap.clear();
        locationMap.clear();
    }
}