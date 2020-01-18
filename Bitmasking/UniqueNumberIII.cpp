#include <iostream>
using namespace std;

// All the numbers are present thrice except for one 
// number which is only present once. Find the unique number.

int uniqueElement(int* array,int elements){
    int unique = 0;
    for(int i=0;i<elements;i++)
        unique = array[i]^array[i]^array[i];
    return unique;
}

int main(){
    int elements;
    cin>>elements;
    int* array = new int[elements];
    for(int i=0;i<elements;i++)
        cin>>array[i];
    cout<<uniqueElement(array,elements)<<endl;
}