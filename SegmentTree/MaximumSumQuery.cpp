#include <iostream>
#include <cmath>
#include <vector>
#define ll long long int
using namespace std;

class Node{
public:
    ll maxValue,maxFromLeft,maxFromRight,totalSum;

    Node(){
        setValue(0);
    }

    void setValue(ll value){
        maxValue = value;totalSum=value;maxFromLeft=value;maxFromRight=value;totalSum=value;
    }

    void setNodeValues(Node* nodeLeft,Node* nodeRight){
        if(nodeLeft!=NULL && nodeRight!=NULL){
            totalSum = nodeLeft->totalSum+nodeRight->totalSum;
            maxFromLeft = max(nodeLeft->maxFromLeft,nodeLeft->totalSum+nodeRight->maxFromLeft);
            maxFromRight = max(nodeRight->maxFromRight,nodeRight->totalSum+nodeLeft->maxFromRight);
            maxValue = max(nodeLeft->totalSum,nodeRight->totalSum,totalSum,maxFromLeft,maxFromRight,nodeLeft->maxFromRight+nodeRight->maxFromLeft,nodeLeft->maxValue,nodeRight->maxValue);
        } else if(nodeLeft.initialized){}
    }

    ll max(ll a,ll b){
        if(a>=b)
            return a;
        return b;
    }

    ll max(ll a,ll b,ll c,ll d,ll e,ll f,ll g,ll h){
        return max(max(max(max(a,b),max(c,d)),max(e,f)),max(g,h));
    }
};

class SegmentTree{
private:
    vector<Node> tree;
    ll elements;

    void buildTree(ll low,ll high,ll treeIndex,ll* array){
        if(low==high){
            tree[treeIndex].setValue(array[low]);
            return;
        }
        ll mid = (low+high)/2;
        buildTree(low,mid,2*treeIndex+1,array);
        buildTree(mid+1,high,2*treeIndex+2,array);
        tree[treeIndex].setNodeValues(&tree[2*treeIndex+1],&tree[2*treeIndex+2]);
    }

    Node queryTree(ll low,ll high,ll treeLowIndex,ll treeHighIndex,ll treeIndex){
        Node resultNode;
        if(treeLowIndex>high || treeHighIndex<low)
            return resultNode;
        else if(low<=treeLowIndex && treeHighIndex<=high)
            return tree[treeIndex];
        ll mid = (treeLowIndex+treeHighIndex)/2;
        Node leftResultSet = queryTree(low,high,treeLowIndex,mid,2*treeIndex+1);
        Node rightResultSet = queryTree(low,high,mid+1,treeHighIndex,2*treeIndex+2);
        resultNode.setNodeValues(&leftResultSet,&rightResultSet);
        return resultNode;
    }

public:
    SegmentTree(ll* array,ll elements){
        this->elements = elements;
        tree = new Node[4*elements+3];
        buildTree(0,elements-1,0,array);
    }

    ll query(ll leftIndex,ll rightIndex){
        Node resultNode = queryTree(leftIndex,rightIndex,0,elements-1,0);
        return resultNode.maxValue;
    }

    void printTree(){
        cout<<"maxValue: ";
        for(ll i=0;i<4*elements+3;i++)
            cout<<tree[i].maxValue<<" "<<tree[i].totalSum<<" "<<tree[i].maxFromLeft<<" "<<tree[i].maxFromRight<<endl;
    }
};

int main(){
    ll elements;
    cin>>elements;
    ll* array = new ll[elements];
    for(ll i=0;i<elements;i++)
        cin>>array[i];
    SegmentTree segmentTree(array,elements);
    // segmentTree.printTree();
    ll queries;
    cin>>queries;
    while(queries-->0){
        ll leftIndex,rightIndex;
        cin>>leftIndex>>rightIndex;
        cout<<segmentTree.query(leftIndex-1,rightIndex-1)<<endl;
        // segmentTree.printTree();
    }
}