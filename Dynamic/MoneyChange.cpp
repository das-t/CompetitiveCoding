#include <iostream>
using namespace std;

long long int MODVALUE = 1000000007;

long long int coinChangeCount(int cost,int elements,int* price){
    // if(remaining==0)
    //     return 1;
    // else if(index<0 || remaining<0)
    //     return 0;
    // else if(memorize[remaining][index]!=0)
    //     return memorize[remaining][index];
    // else{
    //     long long int result = (coinChangeCount(remaining-price[index],index,price,memorize)+
    //             coinChangeCount(remaining,index-1,price,memorize))%MODVALUE;
    //     memorize[remaining][index] = result;
    // }
    // return memorize[remaining][index];
    long long int** memorize = new long long int*[elements];
    for(int i=0;i<elements;i++){
        memorize[i] = new long long int [cost+1];
        for(int j=0;j<=cost;j++)
            memorize[i][j] = 0;
    }
    for(int i=0;i<=cost;i++)
        if(i%price[0]==0)
            memorize[0][i] = 1;
    for(int i=0;i<elements;i++)
        memorize[i][0] = 1;
    for(int i=1;i<elements;i++)
        for(int j=1;j<=cost;j++)
            if(j-price[i]>=0)
                memorize[i][j] = (memorize[i-1][j]+memorize[i][j-price[i]])%MODVALUE;
            else
                memorize[i][j] = memorize[i-1][j];
    long long int result = memorize[elements-1][cost];

    // for(int i=0;i<elements;i++){
    //     for(int j=0;j<=cost;j++)
    //         cout<<memorize[i][j]<<" ";
    //     cout<<endl;
    // }
    delete[] price;
    for(int i=0;i<elements;i++)
        delete[] memorize[i];
    delete[] memorize;
    return result;
}

int main(){
    int testCases;
    cin>>testCases;
    while(testCases-->0){
        int elements,cost;
        cin>>elements;
        int* price = new int[elements];
        for(int i=0;i<elements;i++)
            cin>>price[i];
        cin>>cost;
        cout<<coinChangeCount(cost, elements, price)<<endl;
    }
}