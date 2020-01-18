#include <iostream>
#define MIN -99999
using namespace std;

// A robot is moving in two dimensional grid. The width of the grid has a fixed
// value of 5 while the height of the grid will be given. Robot starts to move 
// from the middle of the width and just below the grid. It can move only in three 
// directions
//      1. Left Upward
//      2. Upward
//      3. Right Upward
// Each cell of the grid is filled with a number (-1 or 0 or 1). When the Robot 
// traverse from that cell, he will collect that number and sum up. The Robot 
// has some power to make the value of all the cell of first 5 ∗ 5 subgrids 
// from -1 to 0. He can use that power only once. Can you help the Robot to 
// get the maximum score?


bool checkValidMove(int,int,int,int**);
int getMaxValue(int rowIndex,int colIndex,int rows,int** array){
    if(!checkValidMove(rowIndex,colIndex,rows,array))
        return 0;
    else
        return array[rowIndex][colIndex] + max(max(MIN,getMaxValue(rowIndex-1,colIndex-1,rows,array)),max(
            getMaxValue(rowIndex-1,colIndex,rows,array),getMaxValue(rowIndex-1,colIndex+1,rows,array)
        ));
}

bool checkValidMove(int rowIndex,int colIndex,int rows,int** array){
    if(rowIndex<0 || colIndex<0 || rowIndex>=rows || colIndex>=5)
        return false;
    else
        return true;
}

int** setMatrix(int** array,int rows,int cols,int startIndex,int** matrix){
    for(int i=0;i<rows;i++)
        for(int j=0;j<5;j++)
            if(i>=startIndex && i-startIndex<cols && array[i][j]==-1)
                matrix[i][j] = 0;
            else
                matrix[i][j] = array[i][j];
}

int main(){
    int testCases;
    cin>>testCases;
    while(testCases-->0){
        int elements;
        cin>>elements;
        int** array = new int*[elements];
        int** matrix = new int*[elements];
        for(int i=0;i<elements;i++){
            array[i] = new int[5];
            matrix[i] = new int[5];
            for(int j=0;j<5;j++)
                cin>>array[i][j];
        }
        int minValue = getMaxValue(elements-1,2,elements,array);
        minValue = max(minValue,getMaxValue(elements-1,1,elements,array));
        minValue = max(minValue,getMaxValue(elements-1,3,elements,array));
        setMatrix(array,elements,5,0,matrix);
        for(int i=0;i<elements;i++){
            setMatrix(array,elements,5,i,matrix);
            minValue = max(minValue,getMaxValue(elements-1,2,elements,matrix));
            minValue = max(minValue,getMaxValue(elements-1,1,elements,matrix));
            minValue = max(minValue,getMaxValue(elements-1,3,elements,matrix));
        }
        cout<<minValue<<endl;
    }
}