#include <iostream>
using namespace std;

bool subsetSum(int* array,int totalSum,int elements){
    bool** memorize = new bool*[elements];
    for(int i=0;i<elements;i++){
        memorize[i] = new bool[totalSum+1];
        for(int j=0;j<=totalSum;j++)
            memorize[i][j] = false;
    }
    for(int i=0;i<=totalSum;i++)
        if(i==array[0]){
            memorize[0][i] = true;
            break;
        }
    for(int i=0;i<elements;i++)
        memorize[i][0] = true;
    for(int i=1;i<elements;i++)
        for(int j=0;j<=totalSum;j++)
            if(j>=array[i])
                memorize[i][j] = memorize[i-1][j] || memorize[i-1][j-array[i]];
            else
                memorize[i][j] = memorize[i-1][j];
    return memorize[elements-1][totalSum];
}
int main(){
    int elements,totalSum;
    cin>>elements>>totalSum;
    int* array = new int[elements];
    for(int i=0;i<elements;i++)
        cin>>array[i];
    if(subsetSum(array,totalSum,elements))
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
}