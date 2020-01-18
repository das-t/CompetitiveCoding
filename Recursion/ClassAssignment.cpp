#include <iostream>
using namespace std;

// In a mathematics class, Teacher ask Alice to find the number of all 
// n digit distinct integers which is formed by the two distinct digits 
// ai and bi but there is a rule to form n digit integer.
// Rule: She has to form n digit integer by using two digits ai and bi 
// without consecutive b

int getNonConsecutive1Combination(int length){
    if(length<=0)
        return 1;
    else if(length==1)
        return 2;
    else
        return getNonConsecutive1Combination(length-1)+
        getNonConsecutive1Combination(length-2);
}

int main(){
    int testCases;
    cin>>testCases;
    for(int i=1;i<=testCases;i++){
        int length;
        cin>>length;
        cout<<"#"<<i<<" : "<<getNonConsecutive1Combination(length)<<endl;
    }
}