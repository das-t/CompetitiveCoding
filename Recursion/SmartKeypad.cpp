#include <iostream>
using namespace std;

// All the possible codes for a number in mobile keypad

string table[] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };
void generateSymbol(int index,int length,string number,string str){
    if(index>=length)
        cout<<str<<endl;
    else{
        string currentChar = string(1,number.at(index));
        for(int i=0;i<table[number.at(index)-'0'].length();i++){
            currentChar = table[number.at(index)-'0'].at(i);
            generateSymbol(index+1,length,number,str+currentChar);
        }
    }
}
int main(){
    string number;
    cin>>number;
    generateSymbol(0,number.length(),number,"");
}