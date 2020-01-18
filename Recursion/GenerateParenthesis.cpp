#include <iostream>
#include <set>
using namespace std;
bool checkValidParenthesis(string);

// Generate all possible balanced parenthesis

set<string, greater<string>> resultSet;
void generateParenthesis(int index,string str){
    if(index<0){
        if(checkValidParenthesis(str))
            resultSet.insert(str);
    }
    else{
        str.at(index) = '(';
        generateParenthesis(index-1,str);
        str.at(index) = ')';
        generateParenthesis(index-1,str);
    }
}

int main(){
    int length;
    cin>>length;
    string str = string(2*length,'x');
    generateParenthesis(2*length-1,str);
    set<string>::iterator itr = resultSet.begin();
    while(itr!=resultSet.end()){
        cout<<*itr<<endl;
        itr++;
    }
}

bool checkValidParenthesis(string str){
    int count = 0;
    for(int i=0;i<str.length();i++){
        if(str.at(i)==')')
            count--;
        else
            count++;
        if(count<0)
            return false;
    }
    if(count==0)
        return true;
    return false;
}
