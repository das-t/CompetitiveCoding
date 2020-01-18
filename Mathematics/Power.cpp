#include <iostream>
using namespace std;

// Take as input x and n, two numbers. Write a function to calculate x 
// raise to power n. Target complexity is O(logn)

long long int power(int base,int exponen){
    long long int result = 1;
    while(exponen>0){
        if((exponen&1)>0)
            result *= base;
        base *= base;
        exponen >>= 1;
    }
    return result;
}

int main(){
    int base,exponen;
    cin>>base>>exponen;
    cout<<power(base,exponen)<<endl;
}