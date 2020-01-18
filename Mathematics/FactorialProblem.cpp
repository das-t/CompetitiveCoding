#include <iostream>
#include <vector>
#define ll long long int
#define MAX 100000005
using namespace std;

// You need to find the the maximum value of x, such that, n! % k^x = 0

ll getMaxPowerDivisble(ll number,ll mod){
    ll power = 0;
    while(number>0){
        power += number/mod;
        number /= mod;
    }
    return power;
}

vector<ll> getPrimeList(){
    vector<ll> primeList;
    bool* array = new bool[MAX];
    for(ll i=0;i<MAX;i++)
        array[i] = true;
    array[0] = array[1] = array[2] = true;
    for(ll i=2;i<MAX;i++){
        if(!array[i])
            continue;
        primeList.push_back(i);
        for(ll j=2;i*j<MAX;j++)
            array[i*j] = false;
    }
    return primeList;
}

ll getLargestPrime(ll number,vector<ll> primeList){
    ll index = primeList.size()-1;
    while(index>0 && (primeList[index]>number || number%primeList[index]!=0))
        index--;
    return primeList[index];
}

int main(){
    int testCases;
    cin>>testCases;
    vector<ll> primeList = getPrimeList();;
    while(testCases-->0){
        long long int n,k;
        cin>>n>>k;
        k = getLargestPrime(k,primeList);
        cout<<getMaxPowerDivisble(n,k)<<endl;
    }
}