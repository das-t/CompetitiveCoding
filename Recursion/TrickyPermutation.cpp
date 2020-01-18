#include <iostream>
#include <algorithm>
using namespace std;

int getLeftIndex(string);
int getIndexLarger(string,int,char);

// Given a string containing duplicates, print all its distinct permutations 
// such that there are no duplicate permutations and all permutations are 
// printed in a lexicographic order.

void generateUniquePermutation(string str){
    while(true){
        int leftIndex = getLeftIndex(str);
        if(leftIndex==-1)
            break;
        int rightIndex = getIndexLarger(str,leftIndex+1,str.at(leftIndex));
        char temp = str.at(leftIndex);
        str.at(leftIndex) = str.at(rightIndex);
        str.at(rightIndex) = temp;
        sort(str.begin()+leftIndex+1,str.end());
        cout<<str<<endl;
    }
}

int getLeftIndex(string str){
    int index = str.size()-2;
    while(index>=0){
        if(str.at(index)<str.at(index+1))
            break;
        index--;
    }
    return index;
}

int getIndexLarger(string str,int index,char ch){
    int minIndex = index;
    for(int i=minIndex+1;i<str.length();i++)
        if(str.at(i)>ch && str.at(i)<str.at(minIndex))
            minIndex = i;
    return minIndex;
}

int main(){
    string str;
    cin>>str;
    sort(str.begin(),str.end());
    cout<<str<<endl;
    generateUniquePermutation(str);
}