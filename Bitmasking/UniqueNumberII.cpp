#include <iostream>
using namespace std;

// All the numbers are present twice except for two numbers 
// which are present only once. Find the unique numbers in 
// linear timeAll the numbers are present twice except for two 
// numbers which are present only once. Find the unique 
// numbers in linear time and with constant extra space

void printUniqueTwoValues(int* array,int elements){
    int xorValue = 0;
    for(int i=0;i<elements;i++)
        xorValue = xorValue^array[i];
    xorValue = xorValue & (~(xorValue-1));
    int uniqueValue = 0;
    for(int i=0;i<elements;i++)
        if((array[i] & xorValue) == 0)
            uniqueValue = uniqueValue^array[i];
    cout<<uniqueValue<<" ";
    uniqueValue = 0;
    for(int i=0;i<elements;i++)
        if((array[i] & xorValue) > 0)
            uniqueValue = uniqueValue^array[i];
    cout<<uniqueValue<<endl;
}
int main(){
    int elements;
    cin>>elements;
    int* array = new int[elements];
    for(int i=0;i<elements;i++)
        cin>>array[i];
    printUniqueTwoValues(array,elements);
}