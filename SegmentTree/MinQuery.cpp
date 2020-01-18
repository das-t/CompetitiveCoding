#include <iostream>
#define INVALID_VALUE 999999999999
#define ll long long int
using namespace std;

void buildTree(ll low,ll high,ll* array,ll treeIndex,ll* treeArray){
    if(low==high){
        treeArray[treeIndex] = array[low];
        return;
    }
    ll mid = (low+high)/2;
    buildTree(low,mid,array,2*treeIndex+1,treeArray);
    buildTree(mid+1,high,array,2*treeIndex+2,treeArray);
    treeArray[treeIndex] = min(treeArray[2*treeIndex+1],treeArray[2*treeIndex+2]);
}

ll query(ll low,ll high,ll* array,ll treeLow,ll treeHigh,ll treeIndex,ll* treeArray){
    // cout<<"low: "<<low<<" high:"<<high<<" treeLow:"<<treeLow<<" treeHigh:"<<treeHigh<<" treeIndex:"<<treeIndex<<endl;
    if(treeLow>high || treeHigh<low)
        return INVALID_VALUE;
    else if(treeLow>=low && treeHigh<=high)
        return treeArray[treeIndex];
    else{
        ll mid = (treeLow+treeHigh)/2;
        return min(query(low,high,array,treeLow,mid,2*treeIndex+1,treeArray),
                query(low,high,array,mid+1,treeHigh,2*treeIndex+2,treeArray));
    }
}

void update(ll index,ll* array,ll value,ll treeLow,ll treeHigh,ll treeIndex,ll* treeArray){
    if(index>treeHigh || index<treeLow)
        return;
    if(treeLow==treeHigh){
        treeArray[treeIndex] = value;
        return;
    }
    ll mid = (treeLow+treeHigh)/2;
    if(index<=mid)
        update(index,array,value,treeLow,mid,2*treeIndex+1,treeArray);
    else
        update(index,array,value,mid+1,treeHigh,2*treeIndex+2,treeArray);
    treeArray[treeIndex] = min(treeArray[2*treeIndex+1],treeArray[2*treeIndex+2]);
}

void prllArray(ll* array,ll elements){
    for(ll i=0;i<elements;i++)
        cout<<array[i]<<" ";
    cout<<endl;
}

int main(){
    ll elements,queries;
    cin>>elements>>queries;
    ll* array = new ll[elements];
    for(ll i=0;i<elements;i++)
        cin>>array[i];
    ll* treeArray = new ll[4*elements+3];
    buildTree(0,elements-1,array,0,treeArray);
    // prllArray(treeArray,4*elements+1);
    while(queries-->0){
        ll option;
        cin>>option;
        if(option==1){
            ll left,right;
            cin>>left>>right;
            cout<<query(left-1,right-1,array,0,elements-1,0,treeArray)<<endl;
        }else{
            ll index,value;
            cin>>index>>value;
            update(index-1,array,value,0,elements-1,0,treeArray);
        }
        // prllArray(treeArray,4*elements+1);
    }
    delete[] treeArray;
    delete[] array;
}