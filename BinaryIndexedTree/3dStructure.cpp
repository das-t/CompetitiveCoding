#include<iostream>
#define MAX 105
#define ll long long int
using namespace std;

ll array[MAX][MAX][MAX];

void cleanArray(){
    for(int i=0;i<MAX;i++)
        for(int j=0;j<MAX;j++)
            for(int k=0;k<MAX;k++)
                array[i][j][k] = 0;                
}

void updateArray(int startX,int startY,int startZ,ll weight,int maxIndex){
    int i=startX,j=startY,k=startZ;
    for(int i=startX;i<=maxIndex;i+=(i&(-i)))
        for(int j=startY;j<=maxIndex;j+=(j&(-j)))
            for(int k = startZ;k<=maxIndex;k += (k&(-k)))
                array[i][j][k] += weight;
}

ll queryArray(int endX,int endY,int endZ){
    int i=endX,j=endY,k=endZ;
    ll totalSum = 0;
    for(int i=endX;i>0;i-=(i&(-i)))
        for(int j=endY;j>0;j-=(j&(-j)))
            for(int k=endZ;k>0;k-=(k&(-k)))
                totalSum += array[i][j][k];
    return totalSum;
}

ll queryVolume(ll startX,ll startY,ll startZ,ll endX,ll endY,ll endZ){
    return queryArray(endX,endY,endZ)-queryArray(endX,endY,startZ-1)-
                queryArray(endX,startY-1,endZ)-queryArray(startX-1,endY,endZ)
                +queryArray(startX-1,endY,startZ-1)+queryArray(endX,startY-1,startZ-1)+
                queryArray(startX-1,startY-1,endZ)-queryArray(startX-1,startY-1,startZ-1);
}

int main(){
    int testCases;
    cin>>testCases;
    while(testCases-->0){
        ll maxIndex,queries;
        cin>>maxIndex>>queries;
        cleanArray();
        while(queries-->0){
            string str;
            cin>>str;
            if(str=="UPDATE"){
                int startX,startY,startZ;
                ll weight;
                cin>>startX>>startY>>startZ>>weight;
                updateArray(startX,startY,startZ,weight-queryVolume(startX,startY,startZ,startX,startY,startZ),maxIndex);
            }
            else{
                int startX,startY,startZ,endX,endY,endZ;
                cin>>startX>>startY>>startZ>>endX>>endY>>endZ;
                cout<<queryVolume(startX,startY,startZ,endX,endY,endZ)<<endl;
            }
        }
    }
}