#include <iostream>
using namespace std;

// xor value of 2 strings of 0's & 1's

string xorValue(string str1,string str2){
    string result = string(str1.length(),'0');
    for(int i=0;i<str1.length();i++)
        if(str1.at(i)!=str2.at(i))
            result.at(i) = '1';
    return result;
}

int main(){
    int testCases;
    cin>>testCases;
    while(testCases-->0){
        string str1,str2;
        cin>>str1>>str2;
        cout<<xorValue(str1,str2)<<endl;
    }
}