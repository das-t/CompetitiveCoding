#include <iostream>
#define ll long long int
using namespace std;

class SegmentTree{
private:
    ll* treeArray;
    ll elements;
    ll invalidValue = -99999999;

    void buildTree(ll low,ll high,ll* array,ll treeIndex){
        if(low==high){
            treeArray[treeIndex] = array[low];
            return;
        }
        ll mid = (low+high)/2;
        buildTree(low,mid,array,2*treeIndex+1);
        buildTree(mid+1,high,array,2*treeIndex+2);
        treeArray[treeIndex] = max(treeArray[2*treeIndex+1],treeArray[2*treeIndex+2]);
    }

    ll query(ll low,ll high,ll treeLowIndex,ll treeHighIndex,ll treeIndex){
        cout<<"low:"<<low<<" high:"<<high<<" treeLow:"<<treeLowIndex<<" treeHigh:"<<treeHighIndex<<" treeIndex:"<<treeIndex<<endl;
        if(treeLowIndex>high || treeHighIndex<low)
            return invalidValue;
        else if(treeLowIndex>=low && treeHighIndex<=high)
            return treeArray[treeIndex];
        else{
            ll mid = (treeLowIndex+treeHighIndex)/2;
            return max(query(low,high,treeLowIndex,mid,2*treeIndex+1),
                        query(low,high,mid+1,treeHighIndex,2*treeIndex+2));
        }
    }

    void update(ll index,ll value,ll treeLowIndex,ll treeHighIndex,ll treeIndex){
        if(index<treeLowIndex || index>treeHighIndex)
            return;
        else if(treeLowIndex==treeHighIndex)
            treeArray[treeIndex] = value;
        else{
            ll mid = (treeLowIndex+treeHighIndex)/2;
            if(index<=mid)
                update(index,value,treeLowIndex,mid,2*treeIndex+1);
            else
                update(index,value,mid+1,treeHighIndex,2*treeIndex+2);
            treeArray[treeIndex] = max(treeArray[2*treeIndex+1],treeArray[2*treeIndex+2]);
        }
    }
public:
    SegmentTree(ll* array,ll elements){
        this->elements = elements;
        treeArray = new ll[4*elements+3];
        buildTree(0,elements-1,array,0);
    }

    ll query(ll low,ll high){
        return query(low,high,0,elements-1,0);
    }

    ll update(ll index,ll value){
        update(index,value,0,elements-1,0);
    }

    void printTree(){
        for(ll i=0;i<4*elements+3;i++)
            cout<<treeArray[i]<<" ";
        cout<<endl;
    }

};
int main(){
    ll elements,queries;
    cin>>elements;
    ll* array = new ll[elements];
    for(ll i=0;i<elements;i++)
        cin>>array[i];
    SegmentTree segmentTree(array,elements);
    segmentTree.printTree();
    // segmentTree.printTree();
    cin>>queries;
    while(queries-->0){
        ll left,right,option;
        cin>>left>>right>>option;
        if(option==1)
            cout<<segmentTree.query(left-1,right-1)<<endl;
        else
            segmentTree.update(left-1,right);
    }
}