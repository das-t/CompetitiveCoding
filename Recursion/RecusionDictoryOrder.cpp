#include <iostream>
#include <algorithm>
using namespace std;

int totalPermutation = 0;
int getRightMostSmallerIndex(string);
int getSmallestElementIndexGreaterThan(string str,int,char);
void swap(string,int,int);

void printPermutation(string str){
    bool isGeneratedAllStrings = false;
    while(!isGeneratedAllStrings){
        int leftSwapIndex = getRightMostSmallerIndex(str);
        if(leftSwapIndex==-1)
            break;
        int rightSwapIndex = getSmallestElementIndexGreaterThan(str,leftSwapIndex+1,str.at(leftSwapIndex));
        // cout<<leftSwapIndex<<" "<<rightSwapIndex<<endl;
        // swap(str,rightSwapIndex,leftSwaIndex);

        char temp = str.at(leftSwapIndex);
    str.at(leftSwapIndex) = str.at(rightSwapIndex);
    str.at(rightSwapIndex) = temp;

        sort(str.begin()+leftSwapIndex+1,str.end());
        cout<<str<<endl;
        totalPermutation++;
    }
}

int getRightMostSmallerIndex(string str){
    int index = str.length()-2;
    while(index>=0)
        if(str.at(index)<str.at(index+1))
            return index;
        else
            index--;
    return index;
}

int getSmallestElementIndexGreaterThan(string str,int index,char ch){
    int minIndex = index;
    for(int i=index+1;i<str.size();i++)
        if(str.at(i)>ch && str.at(i)<str.at(minIndex))
            minIndex = i;
    return minIndex;
}

void swap(string& str,int index1,int index2){
    
}

int main(){
    string str;
    cin>>str;
    printPermutation(str);
    if(totalPermutation==0)
        cout<<endl;
}