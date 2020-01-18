#include <iostream>
using namespace std;

int min(int a,int b,int c){
    return min(a,min(b,c));
}

int main(){
    int rows,cols;
    cin>>rows>>cols;
    int** array = new int*[rows];
    int** memorize = new int*[rows];
    for(int i=0;i<rows;i++){
        array[i] = new int[cols];
        memorize[i] = new int[cols];
        for(int j=0;j<cols;j++){
            cin>>array[i][j];
            memorize[i][j] = 0;
        }
    }
    for(int i=0;i<cols;i++)
        if(array[0][i]==1)
            memorize[0][i] = 1;
    for(int i=0;i<rows;i++)
        if(array[i][0]==1)
            memorize[i][0] = 1;
    for(int i=1;i<rows;i++)
        for(int j=1;j<cols;j++)
            if(array[i][j]==1)
                memorize[i][j] = min(memorize[i-1][j],min(memorize[i-1][j-1],memorize[i][j-1]))+1;
    int maxVal = 0;
    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++)
            maxVal = max(maxVal, memorize[i][j]);
    cout<<maxVal<<endl;
}