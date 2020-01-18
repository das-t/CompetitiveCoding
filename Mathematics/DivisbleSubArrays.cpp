#include <iostream>
#define ll long long int
using namespace std;

ll getCombinations(ll* array,ll elements){
    ll combinations = 0;
    for(ll i=0;i<elements;i++)
        combinations += (array[i]*(array[i]-1))/2;
    if(array[0]>0)
        combinations += array[0];
    return combinations;
}

int main(){
    ll testCases;
    cin>>testCases;
    while(testCases-->0){
        ll elements;
        cin>>elements;
        ll* array = new ll[elements];
        for(ll i=0;i<elements;i++)
            array[i] = 0;
        ll sum = 0;
        for(ll i=0;i<elements;i++){
            ll value;
            cin>>value;
            sum += value;
            sum %= elements;
            sum = (sum+elements)%elements;
            cout<<"current sum: "<<sum<<endl;
            array[sum]++;
        }
        cout<<getCombinations(array,elements)<<endl;
        delete[] array;
    }
}