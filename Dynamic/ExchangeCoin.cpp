#include <iostream>
using namespace std;

long long int coinExchange(long long int weight,long long int* memorize){
    if(weight<=1)
        return weight;
    else if(memorize[weight]!=0)
        return memorize[weight];
    else
        memorize[weight] = max(weight, coinExchange(weight/2,memorize)+
            coinExchange(weight/3,memorize)+coinExchange(weight/4,memorize));
    return memorize[weight];
}

int main(){
    long long int weight;
    cin>>weight;
    long long int* memorize = new long long int[weight];
    for(int i=0;i<weight;i++)
        memorize[weight] = 0;
    cout<<coinExchange(weight,memorize)<<endl;
}