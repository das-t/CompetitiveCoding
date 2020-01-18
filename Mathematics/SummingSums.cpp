#include <iostream>
#define MOD 98765431
#define ll long long int
using namespace std;

// The N (1 ≤ N ≤ 50,000) cows, conveniently numbered 1, 2, …, N, are trying to learn
// some encryption algorithms. After studying a few examples, they have decided to
// make one of their own! However, they are not very experienced at this, so their
// algorithm is very simple: Each cow i is given a starting number Ci
// (0 ≤ Ci < 90,000,000), and then all the cows perform the following process in parallel:
// First, each cow finds the sum of the numbers of the other N-1 cows. After all cows are
// finished, each cow replaces her number with the sum she computed. To avoid very large
// numbers, the cows will keep track of their numbers modulo 98,765,431. They told Canmuu
// the moose about it in November; he was quite impressed. Then one foggy Christmas Eve,
// Canmuu came to say: "Your algorithm is too easy to break! You should repeat it T
// (1 ≤ T ≤ 1,414,213,562) times instead." Obviously, the cows were very frustrated with
// having to perform so many repetitions of the same boring algorithm, so after many hours
// of arguing, Canmuu and the cows reached a compromise: You are to calculate the numberS
// after the encryption is performed!

ll** power(ll** baseMatrix,ll exponenet);
ll** matrixMultiply(ll** matA,ll** matB,ll rowsA,ll colsA,ll colsB);
ll** getInitialTransformMatrix(ll size);
ll** getInitialRowMatrix(ll currentValue,ll totalValue);
ll** getIdentityMatrix(ll size);
void freeMatrix(ll** matrix,ll rows);
void printMatrix(ll** matrix,ll rows,ll cols);

ll getFinalizedValue(ll cows,ll operations,ll currentNumber,ll totalNumber){
    ll** initialTransforMatrix = getInitialTransformMatrix(cows);
    ll** transformExponentMatrix = power(initialTransforMatrix,operations);
    ll** initialRowMatrix = getInitialRowMatrix(currentNumber,totalNumber);
    ll** resultMat = matrixMultiply(transformExponentMatrix,initialRowMatrix,2,2,2);
    ll result = resultMat[0][0];
    freeMatrix(resultMat,2);
    freeMatrix(initialRowMatrix,2);
    freeMatrix(transformExponentMatrix,2);
    freeMatrix(initialTransforMatrix,2);
    return result;
}

ll** power(ll** baseMatrix,ll exponenet){
    ll** resultMat = getIdentityMatrix(2);
    ll** initBase = baseMatrix;
    while(exponenet>0){
        if(exponenet & 1){
            ll** res = matrixMultiply(resultMat,baseMatrix,2,2,2);
            freeMatrix(resultMat,2);
            resultMat = res;
        }
        ll** res = matrixMultiply(baseMatrix,baseMatrix,2,2,2);
        if(initBase != baseMatrix)
            freeMatrix(baseMatrix,2);
        baseMatrix = res;
        exponenet >>= 1;
    }
    return resultMat;
}

ll** matrixMultiply(ll** matA,ll** matB,ll rowsA,ll colsA,ll colsB){
    ll** matrixMul = new ll*[rowsA];
    for(ll i=0;i<rowsA;i++)
        matrixMul[i] = new ll[colsB];
    for(ll i=0;i<rowsA;i++)
        for(ll j=0;j<colsB;j++){
            ll sum = 0;
            for(ll k=0;k<colsA;k++)
                sum = (sum+matA[i][k]*matB[k][j])%MOD;
            matrixMul[i][j] = sum;
        }
    return matrixMul;
}

ll** getInitialTransformMatrix(ll size){
    ll** initialTransformMatix = new ll*[2];
    for(ll i=0;i<2;i++)
        initialTransformMatix[i] = new ll[2];
    initialTransformMatix[0][0]=-1;initialTransformMatix[0][1]=1;
    initialTransformMatix[1][0]=0;initialTransformMatix[1][1]=size-1;
    return initialTransformMatix;
}

ll** getInitialRowMatrix(ll currentValue,ll totalValue){
    ll** initialRowMatrix = new ll*[2];
    for(ll i=0;i<2;i++)
        initialRowMatrix[i] = new ll[1];
    initialRowMatrix[0][0] = currentValue;
    initialRowMatrix[1][0] = totalValue;
    return initialRowMatrix;
}

ll** getIdentityMatrix(ll size){
    ll** matrix = new ll*[size];
    for(ll i=0;i<size;i++){
        matrix[i] = new ll[size];
        for(ll j=0;j<size;j++)
            if(i==j)
                matrix[i][j] = 1;
            else
                matrix[i][j] = 0;
    }
    return matrix;
}

void freeMatrix(ll** matrix,ll rows){
    for(ll i=0;i<rows;i++)
        delete[] matrix[i];
    delete[] matrix;
}

void printMatrix(ll** matrix,ll rows,ll cols){
    for(ll i=0;i<rows;i++){
        for(ll j=0;j<cols;j++)
            cout<<matrix[i][j]<<" ";
        cout<<endl;
    }
}

int main(){
    ll elements,operations;
    cin>>elements>>operations;
    ll* array = new ll[elements];
    ll totalSum = 0;
    for(ll i=0;i<elements;i++){
        cin>>array[i];
        totalSum += array[i];
    }
    for(ll i=0;i<elements;i++)
        cout<<getFinalizedValue(elements,operations,array[i],totalSum)<<endl;
}