#include <iostream>
#include <cmath>
#define ll long long int
using namespace std;

// The coding blocks members went to the success party of their first ever 
// online boot-camp at Murthal. They ordered P number of paranthas. The stall
// has L cooks and each cook has a rank R. A cook with a rank R can cook 1 prata
// in the first R minutes 1 more prata in the next 2R minutes, 1 more prata in
// 3R minutes and so on(he can only cook a complete prata) ( For example if a 
// cook is ranked 2.. he will cook one prata in 2 minutes one more prata in the
// next 4 mins an one more in the next 6 minutes hence in total 12 minutes he
// cooks 3 pratas in 13 minutes also he can cook only 3 pratas as he does not
// have enough time for the 4th prata). Calculate the minimum time needed to cook
// all the paranthas.

ll getMaxTime(ll*,ll,ll);
bool checkPossible(ll,ll,ll*,ll);

ll modifiedBinSearch(ll* array,ll elements,ll parathas){
    ll low=0,high=getMaxTime(array,elements,parathas);
    while(low<high){
        // cout<<"low:"<<low<<" high:"<<high<<endl;
        ll mid = (low+high)/2;
        if(low==high-1 && checkPossible(low,parathas,array,elements))
            return low;
        else if(low==high-1)
            return high;
        else if(checkPossible(mid,parathas,array,elements))
            high = mid;
        else
            low = mid;
    }
    return low;
}

bool checkPossible(ll time,ll parathas,ll* array,ll elements){
    for(ll i=0;i<elements;i++){
        ll currentParatha = 0;
        while(((currentParatha*((ll)currentParatha+1))/2)*array[i] <= time)
            currentParatha++;
        currentParatha--;
        parathas -= currentParatha;
        if(parathas<=0)
            return true;
    }
    return false;
}

ll getMaxTime(ll* array,ll elements,ll parathas){
    ll maxValue = array[0];
    for(ll i=1;i<elements;i++)
        maxValue = max(maxValue,array[i]);
    ll totalSum = (parathas*(parathas+1))/2;
    return totalSum*maxValue;
}

int main(){
    ll totalParathas,elements;
    cin>>totalParathas>>elements;
    ll* array = new ll[elements];
    for(ll i=0;i<elements;i++)
        cin>>array[i];
    cout<<modifiedBinSearch(array,elements,totalParathas)<<endl;
    delete[] array;
}