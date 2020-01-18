#include <iostream>
using namespace std;

int maxProfit(int* price,int transactions,int opMode,int index){
    if(transactions==0 || index<0)
        return 0;
    else if(opMode==0)
        return max(maxProfit(price,transactions,1,index-1)+price[index],
                maxProfit(price,transactions,0,index-1));
    else
        return max(maxProfit(price,transactions-1,1,index-1)-price[index],
                maxProfit(price,transactions,0,index-1));
}

int max(int a,int b){
    if(a>b)
        return a;
    return b;
}

int main(){
    int testCases;
    cin>>testCases;
    while(testCases-->0){
        int transactions,elements;
        cin>>transactions>>elements;
        int* price = new int[elements];
        for(int i=0;i<elements;i++)
            cin>>price[i];
        cout<<maxProfit(price,transactions,0,elements-1)<<endl;
    }
}