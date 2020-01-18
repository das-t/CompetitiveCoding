#include <iostream>
using namespace std;

// You are given an N*M grid. Each cell (i,j) in the grid is either blocked, 
// or empty. The rat can move from position (i,j), down or right on the grid.

bool isValidMove(int,int,string*);

bool generatePath(int rowIndex,int colIndex,string* matrix){
    if(!isValidMove(rowIndex,colIndex,matrix)){
        return false;
    }
    if(rowIndex==0 && colIndex==0){
        matrix[0].at(0) = '1';
        return true;
    }
    else{
        matrix[rowIndex].at(colIndex)='1';
        if(generatePath(rowIndex-1,colIndex,matrix))
            return true;
        if(generatePath(rowIndex,colIndex-1,matrix))
            return true;
        matrix[rowIndex].at(colIndex)='O';
        return false;
    }
}

bool isValidMove(int rowIndex,int colIndex,string* matrix){
    if(rowIndex<0 || colIndex<0)
        return false;
    else if(matrix[rowIndex].at(colIndex)=='O')
        return true;
    else
        return false;
}

void printModifiedMatrix(string* str,int rows,int cols){
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++)
            if(str[i].at(j)=='1')
                cout<<"1 ";
            else
                cout<<"0 ";
        cout<<endl;
    }
}

int main(){
    int rows,cols;
    cin>>rows>>cols;
    string* matrix = new string[rows];
    for(int i=0;i<rows;i++)
        cin>>matrix[i];
    if(generatePath(rows-1,cols-1,matrix))
        printModifiedMatrix(matrix,rows,cols);
    else
        cout<<"-1"<<endl;
    
}