#include <iostream>
#define ll long long int
#define MOD 1000000007
using namespace std;

// Given two non-negative integers N and M, calculate the sum 
// (F(N) + F(N + 1) + … + F(M)) mod 1000000007
// where F(i) denotes fibonacci number at postition i 

ll** power(ll**,ll);
ll** maxtixMultiply(ll**,ll**,ll,ll,ll);
ll** getIdentityMatrix(ll);
ll** getInitialTransformMatrix();
ll** getInitialRowFiboSumMatrix();
void freeMatrix(ll**,ll);
void printMatrix(ll**,ll,ll);
ll getFiboSum(int);

ll getFiboDiff(int startIndex,int endIndex){
    ll sumBeforeStart = getFiboSum(startIndex-1);
    ll sumUptoEnd = getFiboSum(endIndex);
    return (sumUptoEnd-sumBeforeStart+MOD)%MOD;
}

ll getFiboSum(int index){
    if(index<=0)
        return 0;
    ll** transformMatrix = getInitialTransformMatrix();
    ll** transformedExponentMatrix = power(transformMatrix,index-1);
    ll** initialRowMatrix = getInitialRowFiboSumMatrix();
    ll** resultMat = maxtixMultiply(transformedExponentMatrix,initialRowMatrix,3,3,3);
    ll result = resultMat[2][0];
    freeMatrix(resultMat,3);
    freeMatrix(initialRowMatrix,3);
    freeMatrix(transformedExponentMatrix,3);
    freeMatrix(transformMatrix,3);
    return result;
}

ll** power(ll** baseMatrix,ll exponent){
    ll** resultMat = getIdentityMatrix(3);
    ll** initBaseMatrix = baseMatrix;
    while(exponent>0){
        if(exponent & 1){
            ll** res = maxtixMultiply(resultMat,baseMatrix,3,3,3);
            freeMatrix(resultMat,3);
            resultMat = res;
        }
        ll** res = maxtixMultiply(baseMatrix,baseMatrix,3,3,3);
        if(initBaseMatrix != baseMatrix)
            freeMatrix(baseMatrix,3);
        baseMatrix = res;
        exponent >>= 1;
    }
    return resultMat;
}

ll** maxtixMultiply(ll** matA,ll** matB,ll rowsA,ll colsA,ll colsB){
    ll** matrixMul = new ll*[rowsA];
    for(ll i=0;i<rowsA;i++)
        matrixMul[i] = new ll[colsB];
    for(ll i=0;i<rowsA;i++)
        for(ll j=0;j<colsB;j++){
            ll sum = 0;
            for(ll k=0;k<colsA;k++)
                sum += (matA[i][k]*matB[k][j])%MOD;
            matrixMul[i][j] = sum;
        }
    return matrixMul;
}

ll** getIdentityMatrix(ll size){
    ll** identityMat = new ll*[size];
    for(ll i=0;i<size;i++){
        identityMat[i] = new ll[size];
        for(ll j=0;j<size;j++)
            if(i==j)
                identityMat[i][j] = 1;
            else
                identityMat[i][j] = 0;
    }
    return identityMat;
}

ll** getInitialTransformMatrix(){
    ll** transformMat = new ll*[3];
    for(ll i=0;i<3;i++)
        transformMat[i] = new ll[3];
    transformMat[0][0]=0;transformMat[0][1]=1;transformMat[0][2]=0;
    transformMat[1][0]=1;transformMat[1][1]=1;transformMat[1][2]=0;
    transformMat[2][0]=1;transformMat[2][1]=1;transformMat[2][2]=1;
    return transformMat;
}

ll** getInitialRowFiboSumMatrix(){
    ll** initialRowMat = new ll*[3];
    for(ll i=0;i<3;i++)
        initialRowMat[i] = new ll[1];
    initialRowMat[0][0]=0;initialRowMat[1][0]=1;initialRowMat[2][0]=1;
    return initialRowMat;
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
    int testCase;
    cin>>testCase;
    while(testCase-->0){
        ll start,end;
        cin>>start>>end;
        cout<<getFiboDiff(start,end)<<endl;
    }
}