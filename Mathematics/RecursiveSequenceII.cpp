#include <iostream>
#define ll long long int
using namespace std;
ll MOD = 1000000007;

// CONCEPT: FAST MATRIX EXPONENTIATION
// SPOJ : SPP : https://www.spoj.com/problems/SPP/

ll** matrixMultiply(ll** matA,ll** matB,ll rowsA,ll colsA,ll colsB);
ll** power(ll** baseMatrix,ll exponent,ll size);
ll** getInitialTransformMatrix(ll* array,ll elements);
ll** getInitialRowMatrix(ll* array,ll elements);
ll** getIdentityMatrix(ll size);
void freeMatrix(ll** matrix,ll rows);
void printMatrix(ll** matrix,ll rows,ll cols);

ll getIndexValueSum(ll* initialArray,ll* transformArray,ll elements,ll index){
    if(index<=elements){
        ll sum = 0;
        for(ll i=1;i<=index;i++)
            sum += initialArray[i-1];
        sum = (sum+MOD)%MOD;
        return sum;
    }
    ll** transformMatrix = getInitialTransformMatrix(transformArray,elements);
    ll** transformExponentMatrix = power(transformMatrix,index-elements,elements+1);
    ll** initialMatrix = getInitialRowMatrix(initialArray,elements);
    ll** resultMat = matrixMultiply(transformExponentMatrix,initialMatrix,elements+1,elements+1,1);
    ll result = resultMat[elements][0];
    freeMatrix(resultMat,elements+1);
    freeMatrix(initialMatrix,elements+1);
    freeMatrix(transformExponentMatrix,elements+1);
    freeMatrix(transformMatrix,elements+1);
    return result;
}

ll** power(ll** baseMatrix,ll exponent,ll size){
    ll** resultMat = getIdentityMatrix(size);
    ll** initBaseMatrix = baseMatrix;
    while(exponent>0){
        if(exponent & 1){
            ll** res = matrixMultiply(resultMat,baseMatrix,size,size,size);
            freeMatrix(resultMat,size);
            resultMat = res;
        }
        ll** res = matrixMultiply(baseMatrix,baseMatrix,size,size,size);
        if(baseMatrix != initBaseMatrix)
            freeMatrix(baseMatrix,size);
        baseMatrix = res;
        exponent >>= 1;
    }
    return resultMat;
}

ll** matrixMultiply(ll** matA,ll** matB,ll rowsA,ll colsA,ll colsB){
    ll** resMat = new ll*[rowsA];
    for(ll i=0;i<rowsA;i++)
        resMat[i] = new ll[colsB];
    for(ll i=0;i<rowsA;i++)
        for(ll j=0;j<colsB;j++){
            ll sum = 0;
            for(ll k=0;k<colsA;k++){
                sum += (matA[i][k]*matB[k][j])%MOD;
                sum %= MOD;
            }
            resMat[i][j] = sum;
        }
    return resMat;
}

ll** getInitialTransformMatrix(ll* array,ll elements){
    ll** transformMat = new ll*[elements+1];
    for(ll i=0;i<=elements;i++)
        transformMat[i] = new ll[elements+1];
    for(ll i=0;i<=elements;i++)
        for(ll j=0;j<=elements;j++)
            transformMat[i][j]=0;
    for(ll i=0;i<elements-1;i++)
            transformMat[i][i+1] = 1;
    for(ll i=0;i<elements;i++){
        transformMat[elements-1][elements-i-1] = array[i];
        transformMat[elements][elements-i-1] = array[i];
    }
    transformMat[elements][elements] = 1;
    return transformMat;
}

ll** getInitialRowMatrix(ll* array,ll elements){
    ll** initialMat = new ll*[elements+1];
    for(ll i=0;i<=elements;i++)
        initialMat[i] = new ll[1];
    ll sum = 0;
    for(ll i=0;i<elements;i++){
        initialMat[i][0] = array[i];
        sum += array[i];
    }
    initialMat[elements][0] = (sum+MOD)%MOD;
    return initialMat;
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
    int testCases;
    cin>>testCases;
    while(testCases-->0){
        ll elements;
        cin>>elements;
        ll* initialArray = new ll[elements];
        for(ll i=0;i<elements;i++)
            cin>>initialArray[i];
        ll* transformArray = new ll[elements];
        for(ll i=0;i<elements;i++)
            cin>>transformArray[i];
        ll startIndex,endIndex;
        cin>>startIndex>>endIndex>>MOD;
        for(ll i=0;i<elements;i++){
            initialArray[i] %= MOD;
            transformArray[i] %= MOD;
        }
        ll sumBeforeStart = getIndexValueSum(initialArray,transformArray,elements,startIndex-1);
        ll sumUptoEnd = getIndexValueSum(initialArray,transformArray,elements,endIndex);
        ll result = (sumUptoEnd+MOD-sumBeforeStart)%MOD;
        cout<<result<<endl;
    }
}n