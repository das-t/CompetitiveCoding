#include <iostream>
using namespace std;

// No. of digits divisble by first 8 prime numbers

int primes[] = {2,3,5,7,11,13,17,19};

int countSetBits(int number){
    int setBit = 0;
    while(number>0){
        if((number&1)>0)
            setBit++;
        number >>= 1;
    }
    return setBit;
}

long long int getMultiplied(int number){
    int setBit = countSetBits(number);
    long long int multipliedValue = 1;
    int index = 0;
    while(number>0){
        if((number&1)>0)
            multipliedValue *= primes[index];
        number >>= 1;
        index++;
    }
    if((setBit&1)>0)
        return multipliedValue;
    else
        return -multipliedValue;
}

long long int getInclusionExclusionDivision(long long int maxRange){
    long long int countDivisible = 0;
    for(int i=1;i<256;i++){
        long long int multipliedValue = getMultiplied(i);
        countDivisible += maxRange/multipliedValue;
    }
    return countDivisible;
}

int main(){
    int testCases;
    cin>>testCases;
    while(testCases-->0){
        long long int index;
        cin>>index;
        cout<<getInclusionExclusionDivision(index)<<endl;
    }
}