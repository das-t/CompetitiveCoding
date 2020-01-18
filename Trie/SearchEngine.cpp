#include <iostream>
#include <map>
using namespace std;

// Let us see how search engines work. Consider the following simple auto complete feature.
// When you type some characters in the text bar, the engine automatically gives best matching
// options among it's database. Your job is simple. Given an incomplete search text, output
// the best search result.
// Each entry in engine's database has a priority factor attached to it. We consider a
//  result/search suggestion best if it has maximum weight and completes the given incomplete
// search query. For each query in the input, print the maximum weight of the string in the
// database, that completes the given incomplete search string. In case no such string exists
// , print -1.

class Node{
public:
    char data;
    map<char,Node*> children;
    bool terminate;
    int priority;
    Node(char data){
        this->data = data;
        this->terminate = false;
        this->priority = 0;
    }
};

class Trie{
    Node* root;
    int count = 0;
public:
    Trie(){
        root = new Node('\0');
        count = 0;
    }
    void addWord(string str,int priority){
        Node* temp = root;
        for(int i=0;i<str.size();i++){
            char ch = str.at(i);
            if(temp->children.find(ch)!=temp->children.end()){
                temp = temp->children.find(ch)->second;
            } else {
                Node* newNode = new Node(ch);
                temp->children[ch] = newNode;
                temp = newNode;
            }
            temp->priority = max(temp->priority,priority);
        }
        temp->terminate = true;
        temp->priority = max(temp->priority,priority);
    }

    int searchWord(string str){
        Node* temp = root;
        for(int i=0;i<str.size();i++){
            char ch = str.at(i);
            if(temp->children.find(ch)!=temp->children.end())
                temp = temp->children.find(ch)->second;
            else
                return -1;
        }
        return temp->priority;
    }
};

int main(){
    Trie* trie = new Trie();
    int words,queries;
    cin>>words>>queries;
    while(words-->0){
        string str;
        int priority;
        cin>>str>>priority;
        trie->addWord(str,priority);
    }
    while(queries-->0){
        string str;
        cin>>str;
        cout<<trie->searchWord(str)<<endl;
    }
}