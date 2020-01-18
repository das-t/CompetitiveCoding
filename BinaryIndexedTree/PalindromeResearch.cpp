#include <iostream>
#define ll long long int
using namespace std;

class Node{
public:
    ll hash[26] = {0};
    static const int ALPHABETS = 26;

    static bool checkPalindrome(Node node){
        ll oddElements = 0;
        for(ll i=0;i<Node::ALPHABETS;i++)
            if(node.hash[i]%2==1)
                oddElements++;
        if(oddElements>1)
            return false;
        return true;
    }
};

class BIT{
private:
    Node* tree;
    ll elements;
public:
    BIT(string str){
        elements = str.length()+1;
        tree = new Node[str.length()+1];
        for(ll i=1;i<=str.length();i++)
            update(i,str.at(i-1));
    }

    void update(ll index,char newChar){
        while(index<elements){
            if((newChar-'a')>=0 && (newChar-'a')<Node::ALPHABETS)
                tree[index].hash[newChar-'a']++;
            index += (index & (-index));
        }
    }

    void update(ll index,char newChar,char oldChar){
        while(index<elements){
            if((oldChar-'a')>=0 && (oldChar-'a')<Node::ALPHABETS)
                tree[index].hash[oldChar-'a']--;
            if((newChar-'a')>=0 && (newChar-'a')<Node::ALPHABETS)
                tree[index].hash[newChar-'a']++;
            index += (index & (-index));
        }
    }

    Node query(ll index){
        Node result;
        while(index>0){
            for(ll i=0;i<Node::ALPHABETS;i++)
                result.hash[i] += tree[index].hash[i];
            index -= (index & (-index));
        }
        return result;
    }

    bool checkPalindrome(ll leftIndex,ll rightIndex){
        if(rightIndex<leftIndex)
            return false;
        Node leftHash = query(leftIndex-1);
        Node rightHash = query(rightIndex);
        for(ll i=0;i<Node::ALPHABETS;i++)
            rightHash.hash[i] -= leftHash.hash[i];
        return Node::checkPalindrome(rightHash); 
    }

    void printTree(){
        cout<<"printing Tree"<<endl;
        for(ll i=0;i<elements;i++){
            for(ll j=0;j<Node::ALPHABETS;j++)
                cout<<tree[i].hash[j]<<" ";
            cout<<endl;
        }
    }
};
int main(){
    int length,queries;
    cin>>length>>queries;
    string str;
    cin>>str;
    BIT bitTree(str);
    // bitTree.printTree();
    while(queries-->0){
        ll option;
        cin>>option;
        if(option==1){
            ll index;
            char ch;
            cin>>index>>ch;
            bitTree.update(index,ch,str.at(index-1));
            str.at(index-1) = ch;
            // bitTree.printTree();
        } else {
            ll leftIndex,rightIndex;
            cin>>leftIndex>>rightIndex;
            bool isPalindrome = bitTree.checkPalindrome(leftIndex,rightIndex);
            // bitTree.printTree();
            if(isPalindrome)
                cout<<"yes"<<endl;
            else
                cout<<"no"<<endl;
        }
    }
}