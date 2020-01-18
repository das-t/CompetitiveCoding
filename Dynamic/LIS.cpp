#include <iostream>
using namespace std;

int LISLen(int* array,int elements){
    int* memorize = new int[elements];
    for(int i=0;i<elements;i++)
        memorize[i] = 1;
    for(int i=1;i<elements;i++)
        for(int j=0;j<i;j++)
            if(array[i]>array[j])
                memorize[i] = max(memorize[i],memorize[j]+1);
    int maxLen = memorize[0];
    for(int i=1;i<elements;i++)
        maxLen = max(maxLen,memorize[i]);
    delete[] memorize;
    return maxLen;
}

int main(){
    int elements;
    cin>>elements;
    int* array = new int[elements];
    for(int i=0;i<elements;i++)
        cin>>array[i];
    cout<<LISLen(array,elements)<<endl;
}