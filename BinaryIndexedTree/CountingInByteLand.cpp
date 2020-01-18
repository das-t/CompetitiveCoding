#include <iostream>
#define ll long long int
#define MAX 105
using namespace std;

ll array[MAX][MAX][MAX];
void cleanArray(){
    for(int i=0;i<MAX;i++)
        for(int j=0;j<MAX;j++)
            for(int k=0;k<MAX;k++)
                array[i][j][k] = 0;
}

void updateArray(ll startX,ll startY,ll startZ,ll weight,ll maxIndex){
    for(ll i=startX;i<=maxIndex;i+=(i&(-i)))
        for(ll j=startY;j<=maxIndex;j+=(j&(-j)))
            for(ll k=startZ;k<=maxIndex;k+=(k&(-k)))
                array[i][j][k] += weight;
}

ll queryArray(ll endX,ll endY,ll endZ){
    ll totalSum = 0;
    for(ll i=endX;i>0;i-=(i&-i))
        for(ll j=endY;j>0;j-=(j&-j))
            for(ll k=endZ;k>0;k-=(k&-k))
                totalSum += array[i][j][k];
    return totalSum;
}

ll query(ll startX,ll startY,ll startZ,ll endX,ll endY,ll endZ){
    return queryArray(endX,endY,endZ)-queryArray(endX,endY,startZ-1)-queryArray(endX,startY-1,endZ)
    -queryArray(startX-1,endY,endZ)+queryArray(startX-1,startY-1,endZ)+queryArray(startX-1,endY,startZ-1)
    +queryArray(endX,startY-1,startZ-1)-queryArray(startX-1,startY-1,startZ-1);
}

int main(){
    cleanArray();
    int length,queries;
    cin>>length>>queries;
    ll totalPlayers=0;
    while(queries-->0){
        int option;
        cin>>option;
        if(option==1){
            int startX,startY,startZ;
            ll weight;
            cin>>startX>>startY>>startZ>>weight;
            startX++;startY++;startZ++;
            updateArray(startX,startY,startZ,weight,length+1);
            totalPlayers += weight;
        } else {
            int startX,startY,startZ,endX,endY,endZ;
            cin>>startX>>startY>>startZ>>endX>>endY>>endZ;
            startX++;startY++;startZ++;endX++;endY++;endZ++;
            cout<<(totalPlayers-query(startX,startY,startZ,endX,endY,endZ))<<endl;
        }
    }
}