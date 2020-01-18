#include <iostream>
using namespace std;

// Print the minimum number of squares that the knight can not reach without overlap

int minEmptyCells = 9999;
bool checkValidRange(int,int,int**,int);
int getEmptyCells(int**,int);
void calcEmptyCells(int**,int);

void kinghtChessBoard(int rowIndex,int colIndex,int** array,int rows){
    if(array[rowIndex][colIndex]==0)
        calcEmptyCells(array,rows);
    else{
        array[rowIndex][colIndex] = 0;
        if(checkValidRange(rowIndex-2,colIndex-1,array,rows))
            kinghtChessBoard(rowIndex-2,colIndex-1,array,rows);
        if(checkValidRange(rowIndex-2,colIndex+1,array,rows))
            kinghtChessBoard(rowIndex-2,colIndex+1,array,rows);
        if(checkValidRange(rowIndex-1,colIndex+2,array,rows))
            kinghtChessBoard(rowIndex-1,colIndex+2,array,rows);
        if(checkValidRange(rowIndex-1,colIndex-2,array,rows))
            kinghtChessBoard(rowIndex-1,colIndex-2,array,rows);
        if(checkValidRange(rowIndex+2,colIndex-1,array,rows))
            kinghtChessBoard(rowIndex+2,colIndex-1,array,rows);
        if(checkValidRange(rowIndex+2,colIndex+1,array,rows))
            kinghtChessBoard(rowIndex+2,colIndex+1,array,rows);
        if(checkValidRange(rowIndex+1,colIndex-2,array,rows))
            kinghtChessBoard(rowIndex+1,colIndex-2,array,rows);
        if(checkValidRange(rowIndex+1,colIndex+2,array,rows))
            kinghtChessBoard(rowIndex+1,colIndex+2,array,rows);
        calcEmptyCells(array,rows);
        array[rowIndex][colIndex] = 1;
    }
}
int main(){
    int rows;
    cin>>rows;
    int** array = new int*[rows];
    for(int i=0;i<rows;i++)
        array[i] = new int[rows];
    for(int i=0;i<rows;i++)
        for(int j=0;j<rows;j++)
            cin>>array[i][j];
    for(int i=0;i<rows;i++){
        int j=0;
        for(j=0;j<rows;j++)
            if(array[i][j]!=0){
                kinghtChessBoard(i,j,array,rows);
                break;
            }
        if(j<rows)
            break;
    }
    cout<<minEmptyCells<<endl;
}

bool checkValidRange(int rowIndex,int colIndex,int** array,int rows){
    if(rowIndex<0 || colIndex<0 || rowIndex>=rows || colIndex>=rows)
        return false;
    return true;
}

int getEmptyCells(int** array,int rows){
    int emptyCells = 0;
    for(int i=0;i<rows;i++)
        for(int j=0;j<rows;j++)
            if(array[i][j]==1)
                emptyCells++;
    return emptyCells;
}

void calcEmptyCells(int** array,int rows){
    int emptyCells = getEmptyCells(array,rows);
    if(emptyCells<minEmptyCells)
        minEmptyCells = emptyCells;
}