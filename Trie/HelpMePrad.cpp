#include <iostream>
#include <map>
#include <vector>
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
    int count = 0;
public:
    Trie(){
        root = new Node('\0');
        count = 0;
    }

    void addString(string str){
        Node* temp = root;
        for(int i=0;i<str.size();i++){
            char ch = str.at(i);
            if(temp->children.find(ch)!=temp->children.end())
                temp = temp->children.find(ch)->second;
            else{
                Node* newNode = new Node(ch);
                temp->children[ch] = newNode;
                temp = newNode; 
            }
        }
        temp->terminate = true;
    }

    void findString(Node* node,string currString,vector<string>& vec){
        if(!node)
            return;
        else if(node->terminate)
            vec.push_back(currString);
        map<char,Node*>::iterator itr = node->children.begin();
        for(;itr!=node->children.end();itr++){
            findString(itr->second,currString+itr->first,vec);
        }
    }

    vector<string> findString(string str){
        vector<string> stringPrefix;
        Node* temp = root;
        for(int i=0;i<str.size();i++){
            char ch = str.at(i);
            if(temp->children.find(ch)!=temp->children.end())
                temp = temp->children.find(ch)->second;
            else{
                addString(str);
                return stringPrefix;
            }
        }
        findString(temp,"",stringPrefix);
        return stringPrefix;
    }
};

int main(){
    Trie* trie = new Trie();
    int queries;
    cin>>queries;
    while(queries-->0){
        string str;
        cin>>str;
        trie->addString(str);
    }
    cin>>queries;
    while(queries-->0){
        string str;
        cin>>str;
        vector<string> result = trie->findString(str);
        if(result.size()==0)
            cout<<"No suggestions"<<endl;
        else
            for(int i=0;i<result.size();i++)
                cout<<(str+result[i])<<endl;
    }
}