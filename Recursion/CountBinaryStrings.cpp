#include <iostream>
#define MAX 100
using namespace std;

// Count binary strings having no consecutive 1's

long long int combBinaryString(int length,long long int* memorize){
    if(length==1)
        return 2;
    else if(length==0)
        return 1;
    else if(memorize[length]!=0)
        return memorize[length];
    else
        memorize[length] = combBinaryString(length-1,memorize)+combBinaryString(length-2,memorize);
    return memorize[length];
}

int main(){
    int testCases;
    cin>>testCases;
    long long int* memorize = new long long int[MAX];
    for(int i=0;i<MAX;i++)
        memorize[i] = 0;
    while(testCases-->0){
        int length;
        cin>>length;
        cout<<combBinaryString(length,memorize)<<endl;
    }
}