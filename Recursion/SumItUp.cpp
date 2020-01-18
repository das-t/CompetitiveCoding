#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

// You are given an array of numbers and a target number(T) , print all unique 
// combinations in the array whose sum equals the target number T. Note that 
// each number in the array may only be used once in the combination.

set<string> resultSet; 
void addCombination(int*,bool*,int);

void subsetSum(int index,int remSum,int elements,int* array,bool* memorize){
    if(remSum==0)
        addCombination(array,memorize,elements);
    else if(index>=elements || remSum<0)
        return;
    else{
        memorize[index] = true;
        subsetSum(index+1,remSum-array[index],elements,array,memorize);
        memorize[index] = false;
        subsetSum(index+1,remSum,elements,array,memorize);
    }
}

void addCombination(int* array,bool* memorize,int elements){
    string str = "";
    for(int i=0;i<elements;i++)
        if(memorize[i])
            str += to_string(array[i]) + " ";
    if(resultSet.find(str)==resultSet.end())
        cout<<str<<endl;
    resultSet.insert(str);
}

int main(){
    int elements;
    cin>>elements;
    int* array = new int[elements];
    for(int i=0;i<elements;i++)
        cin>>array[i];
    int sum;
    cin>>sum;
    sort(array, array+elements, less<int>());
    bool* memorize = new bool[elements];
    for(int i=0;i<elements;i++)
        memorize[i] = false;
    subsetSum(0,sum,elements,array,memorize);
    if(resultSet.size()==0)
        cout<<"-1"<<endl;
}