#include <iostream>
using namespace std;

// All the numbers are present twice except for one number 
// which is only present once. Find the unique number

int uniqueNumber(int* array,int elements){
    int unique = array[0];
    for(int i=1;i<elements;i++)
        unique = unique ^ array[i];
    return unique;
}

int main(){
    int elements;
    cin>>elements;
    int* array = new int[elements];
    for(int i=0;i<elements;i++)
        cin>>array[i];
    cout<<uniqueNumber(array,elements)<<endl;
}