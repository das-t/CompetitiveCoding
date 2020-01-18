#include <iostream>
using namespace std;

// max XOR value of pair ranged b/w min and max

int xorMaximize(int minRange,int maxRange){
    int maxXOR = 0;
    for(int i=minRange;i<maxRange;i++)
        for(int j=i+1;j<=maxRange;j++)
            if(maxXOR<(i^j))
                maxXOR = i^j;
    return maxXOR;
}

int main(){
    int minValue,maxValue;
    cin>>minValue>>maxValue;
    cout<<xorMaximize(minValue, maxValue)<<endl;    
}