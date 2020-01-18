#include <iostream>
#define MOD 1000000007
using namespace std;

// CONCEPT: FAST MATRIX EXPONENTIATION
// Provide i-th fibonacci number in O(nlogn) time 

long long int** power(long long int**,int,int);
void printMatrix(long long int**,int,int);
long long int** multiplyMatrix(long long int**,long long int**, int,int,int);
void freeMatrix(long long int**,int);
void freeMatrix(long long int**,int);
long long int** getIdentityMatrix(int);

long long int getFibonacciNumber(int index){
    if(index<=0)
        return 0;
    long long int** transform = new long long int*[2];
    for(int i=0;i<2;i++)
        transform[i] = new long long int[2];
    transform[0][0]=0;transform[0][1]=1;transform[1][0]=1;transform[1][1]=1;
    long long int** initial = new long long int*[2];
    for(int i=0;i<2;i++)
        initial[i] = new long long int[1];
    initial[0][0]=0;initial[1][0]=1;
    long long int** matPower = power(transform,index-1,2);
    long long int** matmul = multiplyMatrix(matPower,initial,2,2,1);
    long long int resultValue = matmul[1][0];
    freeMatrix(initial,2);
    freeMatrix(transform,2);
    freeMatrix(matPower,2);
    freeMatrix(matmul,2);
    return resultValue;
}

long long int** power(long long int** baseMatrix,int exponenet,int size){
    long long int** resultMat = getIdentityMatrix(size);
    long long int** initialBase = baseMatrix;
    while(exponenet>0){
        // cout<<"curr exponen: "<<exponenet<<endl;
        if(exponenet & 1){
            // cout<<" mat mult"<<endl;
            long long int** mult = multiplyMatrix(resultMat,baseMatrix,size,size,size);
            // printMatrix(mult,size,size);
            freeMatrix(resultMat,size);
            resultMat = mult;
        }
        long long int** mult = multiplyMatrix(baseMatrix,baseMatrix,size,size,size);
        if(baseMatrix != initialBase)
            freeMatrix(baseMatrix, size);
        baseMatrix = mult;
        exponenet >>= 1;
    }
    return resultMat;
}

void printMatrix(long long int** array,int rows,int cols){
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++)
            cout<<array[i][j]<<" ";
        cout<<endl;
    }
}

long long int** multiplyMatrix(long long int** matA,long long int** matB, int rowsA,int colsA,int colsB){
    long long int** resultMat = new long long int*[rowsA];
    for(int i=0;i<rowsA;i++)
        resultMat[i] = new long long int[colsB];
    for(int i=0;i<rowsA;i++)
        for(int j=0;j<colsB;j++){
            long long int sum = 0;
            for(int k=0;k<colsA;k++)
                sum += matA[i][k]*matB[k][j];
            resultMat[i][j] = sum%MOD;
        }
    return resultMat;
}

void freeMatrix(long long int** array,int rows){
    for(int i=0;i<rows;i++)
        delete[] array[i];
    delete[] array;
}

long long int** getIdentityMatrix(int size){
    long long int** array = new long long int*[size];
    for(int i=0;i<size;i++){
        array[i] = new long long int[size];
        for(int j=0;j<size;j++)
            if(i==j)
                array[i][j] = 1;
            else
                array[i][j] = 0;
    }
    return array;
}

int main(){
    int testCases;
    cin>>testCases;
    while(testCases-->0){
        int index;
        cin>>index;
        cout<<getFibonacciNumber(index)<<endl;
    }
    // long long int** array = new long long int*[3];
    // for(int i=0;i<3;i++){
    //     array[i] = new int[3];
    //     for(int j=0;j<3;j++)
    //         array[i][j] = i*3+j;
    // }
    // long long int** arrayB = new long long int*[3];
    // for(int i=0;i<3;i++){
    //     arrayB[i] = new int[2];
    //     for(int j=0;j<2;j++)
    //         arrayB[i][j] = i*3+j;
    // }
    // printMatrix(array,3,3);
    // printMatrix(arrayB,3,2);
    // // long long int** result = multiplyMatrix(array,arrayB,3,3,2);
    // long long int** result = power(array,2,3);
    // // long long int** result = getIdentityMatrix(3);
    // cout<<"Result"<<endl;
    // printMatrix(result,3,3);
    // cout<<getFibonacciNumber(2)<<endl;
}