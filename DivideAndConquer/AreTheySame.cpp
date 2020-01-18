#include <iostream>
using namespace std;

// IMPORTANT CONCEPT: Divide & Conquer

// Two strings a and b of equal length are called equivalent in one of 
// the two cases: 
//      1.They are equal. 
//      2.If we split string a into two halves of the same size a1 and a2,
//        and string b into two halves of the same size b1 and b2, then one 
//        of the following is correct: 
//              1. a1 is equivalent to b1, and a2 is equivalent to b2 
//              2. a1 is equivalent to b2, and a2 is equivalent to b1

bool checkEqual(string str1,string str2){
    if(str1.length() != str2.length())
        return false;
    else if(str1==str2)
        return true;
    else if(str1.length()==1  || str1.length()%2==1)
        return false;
    else{
        string a1 = str1.substr(0,str1.length()/2);
        string a2 = str1.substr(str1.length()/2,str1.length()-str1.length()/2);
        string b1 = str2.substr(0,str2.length()/2);
        string b2 = str2.substr(str2.length()/2,str2.length()-str2.length()/2);
        if(checkEqual(a1,b1) && checkEqual(a2,b2))
            return true;
        else if(checkEqual(a2,b1) && checkEqual(a1,b2))
            return true;
        else
            return false;
    }
}

int main(){
    int testCases;
    cin>>testCases;
    while(testCases-->0){
        string str1,str2;
        cin>>str1>>str2;
        if(checkEqual(str1,str2))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}