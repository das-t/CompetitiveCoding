#include <iostream>
using namespace std;

int Knapsack0N(int* weight,int* price,int elements,int maxWeight){
    long long int** memorize = new long long int*[elements];
    for(int i=0;i<elements;i++){
        memorize[i] = new long long int[maxWeight+1];
        for(int j=0;j<=maxWeight;j++)
            memorize[i][j] = 0;
    }
    for(int i=1;i<=maxWeight;i++)
        memorize[0][i] = price[0]*(i/price[0]);
    for(int i=1;i<elements;i++)
        for(int j=1;j<=maxWeight;j++)
            if(j>=weight[i])
                memorize[i][j] = max(memorize[i-1][j],price[i]+memorize[i][j-weight[i]]);
            else
                memorize[i][j] = memorize[i-1][j];
    long long int result = memorize[elements-1][maxWeight];
    for(int i=0;i<elements;i++)
        delete[] memorize[i];
    delete[] memorize;
    return result;
}

int main(){
    int elements,maxWeight;
    cin>>elements>>maxWeight;
    int* weight = new int[elements];
    for(int i=0;i<elements;i++)
        cin>>weight[i];
    int* price = new int[elements];
    for(int i=0;i<elements;i++)
        cin>>price[i];
    cout<<Knapsack0N(weight,price,elements,maxWeight)<<endl;
}