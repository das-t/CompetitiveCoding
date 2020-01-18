#include <iostream>
#define MAX 35
using namespace std;

long long int memorize[MAX];

int calcPairing(){
    memorize[0] = 1;
    memorize[1] = 1;
    for(int i=2;i<MAX;i++)
        memorize[i] = memorize[i-1]+memorize[i-2]*(i-1);
}

int main(){
    calcPairing();
    // for(int i=0;i<MAX;i++)
    //     cout<<memorize[i]<<" ";
    // cout<<endl;
    int testCases;
    cin>>testCases;
    while(testCases-->0){
        int index;
        cin>>index;
        cout<<memorize[index]<<endl;
    }
}