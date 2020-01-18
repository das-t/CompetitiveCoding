#include <iostream>
using namespace std;

long long int LISModified(long long int* array,long long int* weight,int elements){
    long long int* memorize = new long long int[elements];
    for(int i=0;i<elements;i++)
        memorize[i] = weight[i];
    for(int i=1;i<elements;i++)
        for(int j=0;j<i;j++)
            if(array[i]>array[j])
                memorize[i] = max(memorize[i],weight[i]+memorize[j]);
    long long int maxValue = memorize[0];
    for(int i=1;i<elements;i++)
        if(memorize[i]>maxValue)
            maxValue = memorize[i];
    delete[] memorize;
    return maxValue;
}

int main(){
    int testCases;
    cin>>testCases;
    while(testCases-->0){
        int elements;
        cin>>elements;
        long long int* array = new long long int[elements];
        for(int i=0;i<elements;i++)
            cin>>array[i];
        long long int* weight = new long long int[elements];
        for(int i=0;i<elements;i++)
            cin>>weight[i];
        cout<<LISModified(array, weight, elements)<<endl;
    }
}