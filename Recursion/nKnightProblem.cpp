#include <iostream>
#include <set>
#include <vector>
using namespace std;

// Take as input N, the size of a chess board. We are asked to place N number 
// of Knights in it, so that no knight can kill other.

bool canPlaceKnight(int,int,int,int**);
void placeKnight(int,int,int,int**);
void unPlaceKnight(int,int,int,int**);
string createSolutionString(int**,int,int);

vector<string> resultSet;

void generateCombination(int rowIndex,int colIndex,int boardSize,int remKnights,int** board){
    if(remKnights==0){
        string str = createSolutionString(board,boardSize,boardSize);
        vector<string>::iterator itr = resultSet.begin();
        while(itr!=resultSet.end())
            if((*itr)==str)
                break;
            else
                itr++;
        if(itr==resultSet.end())
            resultSet.push_back(str);
    } else if(!canPlaceKnight(rowIndex,colIndex,boardSize,board)) {
        return;
    } else {
        placeKnight(rowIndex,colIndex,boardSize,board);
        for(int i=0;i<boardSize;i++)
            for(int j=0;j<boardSize;j++)
                generateCombination(i,j,boardSize,remKnights-1,board);
        unPlaceKnight(rowIndex,colIndex,boardSize,board);
    }
}

void placeKnight(int rowIndex,int colIndex,int boardSize,int** board){
    board[rowIndex][colIndex] = 1;
    if(canPlaceKnight(rowIndex-2,colIndex-1,boardSize,board))
        board[rowIndex-2][colIndex-1] = -1;
    if(canPlaceKnight(rowIndex-2,colIndex+1,boardSize,board))
        board[rowIndex-2][colIndex+1] = -1;
    if(canPlaceKnight(rowIndex-1,colIndex-2,boardSize,board))
        board[rowIndex-1][colIndex-2] = -1;
    if(canPlaceKnight(rowIndex-1,colIndex+2,boardSize,board))
        board[rowIndex-1][colIndex+2] = -1;
    if(canPlaceKnight(rowIndex+2,colIndex-1,boardSize,board))
        board[rowIndex+2][colIndex-1] = -1;
    if(canPlaceKnight(rowIndex+2,colIndex+1,boardSize,board))
        board[rowIndex+2][colIndex+1] = -1;
    if(canPlaceKnight(rowIndex+1,colIndex-2,boardSize,board))
        board[rowIndex+1][colIndex-2] = -1;
    if(canPlaceKnight(rowIndex+1,colIndex+2,boardSize,board))
        board[rowIndex+1][colIndex+2] = -1;
}

void unPlaceKnight(int rowIndex,int colIndex,int boardSize,int** board){
    board[rowIndex][colIndex] = 0;
    int row=rowIndex-2,col=colIndex-1;
    if(row>=0 && col>=0 && row<boardSize && col<boardSize && board[row][col]==-1)
        board[row][col] = 0;
    row=rowIndex-2;col=colIndex+1;
    if(row>=0 && col>=0 && row<boardSize && col<boardSize && board[row][col]==-1)
        board[row][col] = 0;
    row=rowIndex-1;col=colIndex-2;
    if(row>=0 && col>=0 && row<boardSize && col<boardSize && board[row][col]==-1)
        board[row][col] = 0;
    row=rowIndex-1;col=colIndex+2;
    if(row>=0 && col>=0 && row<boardSize && col<boardSize && board[row][col]==-1)
        board[row][col] = 0;

    row=rowIndex+2;col=colIndex-1;
    if(row>=0 && col>=0 && row<boardSize && col<boardSize && board[row][col]==-1)
        board[row][col] = 0;
    row=rowIndex+2;col=colIndex+1;
    if(row>=0 && col>=0 && row<boardSize && col<boardSize && board[row][col]==-1)
        board[row][col] = 0;
    row=rowIndex+1;col=colIndex-2;
    if(row>=0 && col>=0 && row<boardSize && col<boardSize && board[row][col]==-1)
        board[row][col] = 0;
    row=rowIndex+1;col=colIndex+2;
    if(row>=0 && col>=0 && row<boardSize && col<boardSize && board[row][col]==-1)
        board[row][col] = 0;
    
}

bool canPlaceKnight(int rowIndex,int colIndex,int boardSize,int** board){
    if(rowIndex<0 || colIndex<0 || rowIndex>=boardSize || colIndex>=boardSize)
        return false;
    else if(board[rowIndex][colIndex]!=0)
        return false;
    return true;
}

string createSolutionString(int** board,int rows,int cols){
    string result;
    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++)
            if(board[i][j]==1)
                result += "{"+to_string(i)+"-"+to_string(j)+"} ";
    return result;
}

int main(){
    int board;
    cin>>board;
    int** memorize = new int*[board];
    for(int i=0;i<board;i++){
        memorize[i] = new int[board];
        for(int j=0;j<board;j++)
            memorize[i][j] = 0;
    }
    for(int i=0;i<board;i++)
        for(int j=0;j<board;j++)
            generateCombination(i,j,board,board,memorize);
    for(vector<string>::iterator itr=resultSet.begin();itr!=resultSet.end();itr++)
        cout<<*itr<<" ";
    cout<<endl<<resultSet.size()<<endl;
}