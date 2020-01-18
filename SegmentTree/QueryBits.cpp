#include <iostream>
#define ll long long int
#define MOD 1000000007
using namespace std;

class Node{
public:
    ll integerValue,propagateValue;
    static ll const DEFAULT_VALUE = -1;
};

class SegmentTree{
private:
    Node* treeArray;
    ll elements;

    ll power(ll base,ll exponenet){
        ll result = 1;
        while(exponenet>0){
            if(exponenet & 1)
                result = (result*base)%MOD;
            base = (base*base)%MOD;
            exponenet >>= 1;
        }
        return result;
    }

    ll changeValueAtIndex(ll index,ll length,ll value){
        if(value == 0)
            treeArray[index].integerValue = 0;
        else{
            ll value = power(2,length);
            value = (value-1+MOD)%MOD;
            treeArray[index].integerValue = value;
        }
    }
    void buildTree(ll low,ll high,ll treeIndex,ll* array){
        if(low==high){
            treeArray[treeIndex].integerValue = array[low];
            treeArray[treeIndex].propagateValue = Node::DEFAULT_VALUE;
            return;
        }
        ll mid = (low+high)/2;
        buildTree(low,mid,2*treeIndex+1,array);
        buildTree(mid+1,high,2*treeIndex+2,array);
        treeArray[treeIndex].integerValue = (2*treeArray[2*treeIndex+1].integerValue+
                                        treeArray[2*treeIndex+2].integerValue)%MOD;
        treeArray[treeIndex].propagateValue = Node::DEFAULT_VALUE;
    }

    void updateTree(ll left,ll right,ll value,ll treeLeftIndex,ll treeRightIndex,ll treeIndex){
        if(treeLeftIndex>right || treeRightIndex<left)
            return;
        else if(treeLeftIndex==treeRightIndex){
            treeArray[treeIndex].integerValue = value;
            treeArray[treeIndex].propagateValue = Node::DEFAULT_VALUE;
            return;
        }
        // propagate value
        ll mid = (treeLeftIndex+treeRightIndex)/2;
        if(treeArray[treeIndex].propagateValue != Node::DEFAULT_VALUE){
            changeValueAtIndex(2*treeIndex+1,mid-treeLeftIndex+1,treeArray[treeIndex].propagateValue);
            changeValueAtIndex(2*treeIndex+2,treeRightIndex-mid-1+1,treeArray[treeIndex].propagateValue);
            treeArray[2*treeIndex+1].propagateValue = treeArray[treeIndex].propagateValue;
            treeArray[2*treeIndex+2].propagateValue = treeArray[treeIndex].propagateValue;
            treeArray[treeIndex].propagateValue = Node::DEFAULT_VALUE;
        }
        if(left<=treeLeftIndex && treeRightIndex<=right){
            changeValueAtIndex(treeIndex,treeRightIndex-treeLeftIndex+1,value);
            treeArray[treeIndex].propagateValue = value;
            return;
        }
        updateTree(left,right,value,treeLeftIndex,mid,2*treeIndex+1);
        updateTree(left,right,value,mid+1,treeRightIndex,2*treeIndex+2);
        treeArray[treeIndex].integerValue = (power(2,treeRightIndex-mid)*treeArray[2*treeIndex+1].integerValue+
                                        treeArray[2*treeIndex+2].integerValue)%MOD;
    } 

    ll queryTree(ll left,ll right,ll treeLeftIndex,ll treeRightIndex,ll treeIndex){
        if(treeLeftIndex>right || treeRightIndex<left)
            return 0;
        ll mid = (treeLeftIndex+treeRightIndex)/2;
        if(treeArray[treeIndex].propagateValue != Node::DEFAULT_VALUE){
            if(2*treeIndex+1 < 4*elements+3){
                changeValueAtIndex(2*treeIndex+1,mid-treeLeftIndex+1,treeArray[treeIndex].propagateValue);
                treeArray[2*treeIndex+1].propagateValue = treeArray[treeIndex].propagateValue;
            }
            if(2*treeIndex+2 < 4*elements+3){
                changeValueAtIndex(2*treeIndex+2,treeRightIndex-mid-1+1,treeArray[treeIndex].propagateValue);
                treeArray[2*treeIndex+2].propagateValue = treeArray[treeIndex].propagateValue;
            }
            treeArray[treeIndex].propagateValue = Node::DEFAULT_VALUE;
        }
        // updation done... continue as usual
        if(left<=treeLeftIndex && treeRightIndex<=right){
            return treeArray[treeIndex].integerValue;
        }
        ll leftValue = queryTree(left,right,treeLeftIndex,mid,2*treeIndex+1);
        ll rightValue = queryTree(left,right,mid+1,treeRightIndex,2*treeIndex+2);
        return (power(2,min(treeRightIndex,right)-mid)*leftValue+rightValue)%MOD;
    }

public:
    SegmentTree(ll* array,ll elements){
        buildTree(array,elements);
        this->elements = elements;
    }

    void printTree(){
        cout<<"Elements: ";
        for(ll i=0;i<4*elements+3;i++)
            cout<<treeArray[i].integerValue<<" ";
        cout<<"\nPropagat: ";
        for(ll i=0;i<4*elements+3;i++)
            cout<<treeArray[i].propagateValue<<" ";
        cout<<endl;
    }
    void buildTree(ll* array,ll elements){
        treeArray = new Node[4*elements+3];
        buildTree(0,elements-1,0,array);
    }

    void updateToZpero(ll leftIndex,ll rightIndex){
        updateTree(leftIndex,rightIndex,0,0,elements-1,0);
    }

    void updateToOne(ll leftIndex,ll rightIndex){
        updateTree(leftIndex,rightIndex,1,0,elements-1,0);
    }

    ll query(ll leftIndex,ll rightIndex){
        return queryTree(leftIndex,rightIndex,0,elements-1,0);
    }
};

int main(){
    ll length,queries;
    cin>>length>>queries;
    ll* array = new ll[length];
    for(ll i=0;i<length;i++)
        array[i] = 0;
    SegmentTree segmentTree(array,length);
    while(queries-->0){
        ll option,left,right;
        cin>>option>>left>>right;
        if(option==0)
            segmentTree.updateToZpero(left,right);
        else if(option==1)
            segmentTree.updateToOne(left,right);
        else
            cout<<segmentTree.query(left,right)<<endl;
    }
} 