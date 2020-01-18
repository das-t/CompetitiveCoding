#include <iostream>
#define ll long long int
#define MOD 1000000000
using namespace std;

// CONCEPT : GENERALIZED MATRIX EXPONENTIATION
// SPOJ Question : SEQ - Recursive Sequence

ll** power(ll** baseMatrix,ll exponent,ll size);
ll** multiplyMatrix(ll** matA,ll** matB,ll rowsA,ll colsA,ll colsB);
ll** getInitialTransformMatrix(ll* array,ll elements);
ll** convertArrayToRowMatrix(ll* array,ll elements);
ll** getIdentityMatrix(ll size);
void printMatrix(ll** matrix,ll rows,ll cols);
void freeMatrix(ll** matrix,ll rows);

ll getIndexValue(ll* initials,ll* conversion,ll elements,ll index){
    if(index<=elements)
        return initials[index-1];
    ll** transformMatrix = getInitialTransformMatrix(conversion,elements);
    ll** initialRowMatrix = convertArrayToRowMatrix(initials,elements);
    ll** tansformedPowerMatrix = power(transformMatrix,index-elements,elements);
    ll** resultMat = multiplyMatrix(tansformedPowerMatrix,initialRowMatrix,elements,elements,1);
    ll result = resultMat[elements-1][0];
    freeMatrix(resultMat,elements);
    freeMatrix(tansformedPowerMatrix,elements);
    freeMatrix(initialRowMatrix,elements);
    freeMatrix(transformMatrix,elements);
    return result;
}

ll** power(ll** baseMatrix,ll exponent,ll size){
    ll** resultMat = getIdentityMatrix(size);
    ll** initialBase = baseMatrix;
    while(exponent>0){
        if(exponent & 1){
            ll** resMat = multiplyMatrix(resultMat,baseMatrix,size,size,size);
            freeMatrix(resultMat,size);
            resultMat = resMat;
        }
        ll** resMat = multiplyMatrix(baseMatrix,baseMatrix,size,size,size);
        if(baseMatrix != initialBase)
            freeMatrix(baseMatrix,size);
        baseMatrix = resMat;
        exponent >>= 1;
    }
    return resultMat;
}

ll** multiplyMatrix(ll** matA,ll** matB,ll rowsA,ll colsA,ll colsB){
    ll** matrix = new ll*[rowsA];
    for(ll i=0;i<rowsA;i++)
        matrix[i] = new ll[colsB];
    for(ll i=0;i<rowsA;i++)
        for(ll j=0;j<colsB;j++){
            ll sum = 0;
            for(ll k=0;k<colsA;k++)
                sum += (matA[i][k]*matB[k][j])%MOD;
            matrix[i][j] = sum%MOD;
        }
    return matrix;
}

ll** convertArrayToRowMatrix(ll* array,ll elements){
    ll** rowMatrix = new ll*[elements];
    for(ll i=0;i<elements;i++){
        rowMatrix[i] = new ll[1];
        rowMatrix[i][0] = array[i];
    }
    return rowMatrix;
}

ll** getInitialTransformMatrix(ll* array,ll elements){
    ll** transformMat = new ll*[elements];
    for(ll i=0;i<elements;i++){
        transformMat[i] = new ll[elements];
        for(ll j=0;j<elements;j++)
            if(j==i+1)
                transformMat[i][j] = 1;
            else
                transformMat[i][j] = 0;
    }
    for(int i=0;i<elements;i++)
        transformMat[elements-1][elements-1-i] = array[i];
    return transformMat;
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

void printMatrix(ll** matrix,ll rows,ll cols){
    for(ll i=0;i<rows;i++){
        for(ll j=0;j<cols;j++)
            cout<<matrix[i][j]<<" ";
        cout<<endl;
    }
}

void freeMatrix(ll** matrix,ll rows){
    for(ll i=0;i<rows;i++)
        delete[] matrix[i];
    delete[] matrix;
}

int main(){
    int testCase;
    cin>>testCase;
    while(testCase-->0){
        ll elements;
        cin>>elements;
        ll* initials = new ll[elements];
        for(ll i=0;i<elements;i++)
            cin>>initials[i];
        ll* conversion = new ll[elements];
        for(ll i=0;i<elements;i++)
            cin>>conversion[i];
        ll index;
        cin>>index;
        cout<<getIndexValue(initials,conversion,elements,index)<<endl;
        delete[] conversion;
        delete[] initials;
    }
}