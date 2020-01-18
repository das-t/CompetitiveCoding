#include <iostream>
#define MAX 1000000
using namespace std;
int maxConsecutive1s(int*,int);
void placeFinalizedArray(int*,int);

int finalArray[MAX];
int currentMaxLength = 0;

int flipAtMostKBits(int inversion,int index,int length,int* array,int** memorize) {
    if(index<0 || inversion==0)
        return maxConsecutive1s(array,length);
    else if(memorize[inversion][index]!=0)
        return memorize[inversion][index];
    else{
        int maxWOInvert = flipAtMostKBits(inversion,index-1,length,array,memorize);
        int maxWInvert = 0;
        if(array[index]==0){
            array[index] = 1;
            maxWInvert = flipAtMostKBits(inversion-1,index-1,length,array,memorize);
            array[index] = 0;
        }
        if(maxWInvert>maxWOInvert){
            currentMaxLength = maxWInvert;
            memorize[inversion][index] = maxWInvert;
            return maxWInvert;
        }
        else{
            currentMaxLength = maxWOInvert;
            memorize[inversion][index] = maxWOInvert;
            return maxWOInvert;
        }
    }
}

void placeFinalizedArray(int* array,int length){
    for(int i=0;i<length;i++)
        finalArray[i] = array[i];
}

int printArray(int* array,int length){
    for(int i=0;i<length;i++)
        cout<<array[i]<<" ";
    cout<<endl;
}

int maxConsecutive1s(int* array,int length){
    int maxLength = 0;
    int currentLength = 0;
    for(int i=0;i<length;i++){
        if(array[i]==1)
            currentLength++;
        else{
            if(currentLength>maxLength)
                maxLength = currentLength;
            currentLength = 0;
        }
    }
    if(currentLength>maxLength)
        maxLength = currentLength;
    if(maxLength>currentMaxLength)
        placeFinalizedArray(array, length);
    return maxLength;
}

int main(){
    int elements,inversion;
    cin>>elements>>inversion;
    int array[elements];
    for(int i=0;i<elements;i++)
        cin>>array[i];
    int** memeorize = new int*[inversion+1];
    for(int i=0;i<=inversion;i++){
        memeorize[i] = new int[elements];
        for(int j=0;j<elements;j++)
            memeorize[i][j] = 0;
    }
    cout<<flipAtMostKBits(inversion, elements-1, elements, array, memeorize)<<endl;
    printArray(finalArray, elements);
    for(int i=0;i<=inversion;i++)
        delete[] memeorize[i];
    delete[] memeorize;
}