#include <iostream>
#include <map>
using namespace std;

class Node{
public:
    char data;
    map<char,Node*> children;
    bool terminate;
    Node(char data){
        this->data = data;
        terminate = false;
    }
};

class Trie{
    Node* root;
    int count=0;
public:
    Trie(){
        root = new Node('\0');
        count = 0;
    }

    void addNumber(int number){
        Node* head = root;
        for(int i=31;i>=0;i--){
            int value = (number>>i)
        }
    }

    int getMaxXorPairValue(){
        return 0;
    }
};

int main(){
    Trie* trie = new Trie();
    int elements;
    cin>>elements;
    trie->addNumber(0);
    int previousValue = 0;
    while(elements-->0){
        int value;
        cin>>value;
        previousValue ^= value;
        trie->addNumber(previousValue);
    }
    cout<<trie->getMaxXorPairValue()<<endl;
}