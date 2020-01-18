#include <iostream>
#include <set>
#include <vector>
using namespace std;

// Take as input str, a string. Assume that value of a=1, b=2, c=3, d=4, …. z=26. 
// Print all possible codes for the string.

set<string,less<string>> resultSet;
void generateCode(int number,string str){
    if(number<=0)
        resultSet.insert(str);
    else{
        char lastIndex = 'a'+(char)(number%10)-1;
        generateCode(number/10,string(1,lastIndex)+str);
        if(number>=10 && number%100<=26 && number%100!=0){
            lastIndex = 'a'+(char)(number%100)-1;
            generateCode(number/100,string(1,lastIndex)+str);
        }
    }
}

int main(){
    int number;
    cin>>number;
    generateCode(number,"");
    set<string>::iterator itr = resultSet.begin();
    vector<string> resultVec;
    while(itr!=resultSet.end()){
        resultVec.push_back(*itr);
        itr++;
    }
    resultSet.clear();
    for(int i=0;i<resultVec.size();i++){
        if(i==0)
            cout<<"[";
        else
            cout<<", ";
        cout<<resultVec[i];
        if(i==resultVec.size()-1)
            cout<<"]"<<endl;
    }
    resultVec.clear();
}