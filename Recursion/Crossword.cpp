#include <iostream>
#include <vector>
using namespace std;

// You are given a dictionary consisting of N words each containing lowercase letters 
// 'a'-'z'. You also have MxM crossword consisting of lowercase letters 'a'-'z'. You 
// want to print all possible words that can be formed by a sequence of adjacent 
// characters. Note that you can move to any of 8 adjacent characters, but a word 
// should not have multiple instances of same cell.

bool isValidMove(int,int,string*,int,int,char);

bool isFormWord(int index,int rowIndex,int colIndex,string* crossword,int rows,int cols,string word){
    if(index>=word.length())
        return true;
    else if(!isValidMove(rowIndex,colIndex,crossword,rows,cols,word.at(index)))
        return false;
    else{
        char currentChar = crossword[rowIndex].at(colIndex);
        crossword[rowIndex].at(colIndex) = '-';
        bool outputValue = false;
        if(!outputValue)
            outputValue = isFormWord(index+1,rowIndex-1,colIndex-1,crossword,rows,cols,word);
        if(!outputValue)
            outputValue = isFormWord(index+1,rowIndex-1,colIndex,crossword,rows,cols,word);
        if(!outputValue)
            outputValue = isFormWord(index+1,rowIndex-1,colIndex+1,crossword,rows,cols,word);
        if(!outputValue)
            outputValue = isFormWord(index+1,rowIndex,colIndex-1,crossword,rows,cols,word);
        if(!outputValue)
            outputValue = isFormWord(index+1,rowIndex,colIndex+1,crossword,rows,cols,word);
        if(!outputValue)
            outputValue = isFormWord(index+1,rowIndex+1,colIndex-1,crossword,rows,cols,word);
        if(!outputValue)
            outputValue = isFormWord(index+1,rowIndex+1,colIndex,crossword,rows,cols,word);
        if(!outputValue)
            outputValue = isFormWord(index+1,rowIndex+1,colIndex+1,crossword,rows,cols,word);
        crossword[rowIndex].at(colIndex) = currentChar;
        return outputValue;
    }
}

bool checkIfWordExists(string* crossword,int rows,int cols,string word){
    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++)
            if(crossword[i].at(j)==word.at(0))
                if(isFormWord(0,i,j,crossword,rows,cols,word))
                    return true;
    return false;
}

bool isValidMove(int rowIndex,int colIndex,string* crossword,int rows,int cols,char ch){
    if(rowIndex<0 || colIndex<0 || rowIndex>=rows || colIndex>=cols)
        return false;
    else if(crossword[rowIndex].at(colIndex)!=ch)
        return false;
    else
        return true;
}

int main(){
    int dictionary;
    cin>>dictionary;
    vector<string> dict;
    for(int i=0;i<dictionary;i++){
        string word;
        cin>>word;
        dict.push_back(word);
    }
    int elements;
    cin>>elements;
    string* crossword = new string[elements];
    for(int i=0;i<elements;i++)
        cin>>crossword[i];
    for(int i=0;i<dict.size();i++)
        if(checkIfWordExists(crossword,elements,elements,dict.at(i)))
            cout<<dict.at(i)<<" ";
    cout<<endl;
}

/*
5
a ab b ad zx
2
ac
bd
*/