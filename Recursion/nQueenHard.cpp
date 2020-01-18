#include <iostream>
#include <vector>
using namespace std;

bool canPlaceQueen(int,int,vector<int>&);

// Place n Queens in nXn chessboard so that no piece attacks another

int combination = 0;
void combineQueen(int rowIndex,int rows,vector<int>& array){
    if(rowIndex>=rows)
        combination++;
    else{
        for(int i=0;i<rows;i++) // place in each column for rowIndex
            if(canPlaceQueen(rowIndex,i,array)){
                array.push_back(i);
                combineQueen(rowIndex+1,rows,array);
                array.pop_back();
            }
    }
}

bool canPlaceQueen(int rowIndex,int colIndex,vector<int>& array){
    for(int i=0;i<array.size();i++){
        if(array.at(i)==colIndex)
            return false;
        else if(i+array.at(i)==colIndex+rowIndex)
            return false;
        else if(i-array.at(i)==rowIndex-colIndex)
            return false;
    }
    return true;
}

int main(){
    int queens;
    cin>>queens;
    vector<int> array;
    combineQueen(0,queens,array);
    cout<<combination<<endl;
}