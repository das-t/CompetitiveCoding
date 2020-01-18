#include <iostream>
using namespace std;

int knapsackProblem(int* weight,int* price,int elements,int maxWeight){
    int** memorize = new int*[elements];
    for(int i=0;i<elements;i++){
        memorize[i] = new int[maxWeight+1];
        for(int j=0;j<=maxWeight;j++)
            memorize[i][j] = 0;
    }
    for(int i=0;i<=maxWeight;i++)
        if(weight[0]<=i)
            memorize[0][i] = price[0];
    for(int i=1;i<elements;i++)
        for(int j=1;j<=maxWeight;j++)
            if(j>=weight[i])
                memorize[i][j] = max(memorize[i-1][j],memorize[i-1][j-weight[i]]+price[i]);
            else
                memorize[i][j] = memorize[i-1][j];

    int result = memorize[elements-1][maxWeight];
    for(int i=0;i<elements;i++)
        delete[] memorize[i];
    delete[] memorize;
    return result;
}

int main(){
    int elements,maxWeight;
    cin>>elements>>maxWeight;
    int* weight = new int[elements];
    int* price = new int[elements];
    for(int i=0;i<elements;i++)
        cin>>weight[i];
    for(int i=0;i<elements;i++)
        cin>>price[i];
    cout<<knapsackProblem(weight, price, elements, maxWeight)<<endl;
}