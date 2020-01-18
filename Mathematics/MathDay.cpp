#include <iostream>
using namespace std;

// Given three positive integers A,N,P. Compute (A^(N!))%P.

long long int power(long long int base,long long int exponenet,long long int mod){
    long long int result = 1;
    while(exponenet>0){
        if(exponenet&1)
            result *= base;
        exponenet >>= 1;
        base *= base;
        result %= mod;
        base %= mod;
    }
    return result;
}

int main(){
    long long int testCases;
    cin>>testCases;
    while(testCases-->0){
        long long int a,n,p;
        cin>>a>>n>>p;
        a = a%p;
        long long int result = a;
        for(int i=1;i<=n;i++)
            result = power(result,i,p);
        cout<<result<<endl;
    }
}