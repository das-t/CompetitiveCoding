#include <iostream>
using namespace std;

// count the no of set-bits in for all numbers between a and b (both inclusive)

int countSetBitsUptoNum(long long int number){
    number += 1;
    int countBit = 0;
    long long int power2 = 1;
    while(power2 < number){
        countBit += (number/(power2<<1))*power2;
        if(power2>1)
            countBit += (number%(power2>>1));
        power2 <<= 1; 
    }
    return countBit;
}

int main(){
    int testCases;
    cin>>testCases;
    while(testCases-->0){
        long long int minRange,maxRange;
        cin>>minRange>>maxRange;
        int setBits = countSetBitsUptoNum(maxRange)-countSetBitsUptoNum(minRange-1);
        cout<<setBits<<endl;
    }
}