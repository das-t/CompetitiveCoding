#include <iostream>
#include <vector>
#define ll long long int
#define MOD 1000000007
using namespace std;

ll* segMent_value;

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

ll gcd(ll a,ll b){
    if(a==0)
        return b;
    else if(b==0)
        return a;
    else if(a<b)
        return gcd(b,a);
    else if(a%b==0)
        return b;
    else
        return gcd(b,a%b);
}

void buildTree(ll low,ll high,ll treeIndex,ll* array,ll* segmentTree){
    if(low==high){
        segmentTree[treeIndex] = getFibonacciNumber(array[low])%MOD;
        return;
    }
    ll mid = (low+high)/2;
    buildTree(low,mid,2*treeIndex+1,array,segmentTree);
    buildTree(mid+1,high,2*treeIndex+2,array,segmentTree);
    segmentTree[treeIndex] = gcd(segmentTree[2*treeIndex+1],segmentTree[2*treeIndex+2])%MOD;
}

ll queryTree(ll low,ll high,ll treeLowIndex,ll treeHighIndex,ll treeIndex,ll* segmentTree){
    if(treeLowIndex>high || treeHighIndex<low)
        return 0;
    else if(low<=treeLowIndex && treeHighIndex<=high)
        return segmentTree[treeIndex];
    ll mid = (treeLowIndex+treeHighIndex)/2;
    ll leftGCD = queryTree(low,high,treeLowIndex,mid,2*treeIndex+1,segmentTree);
    ll rightGCD = queryTree(low,high,mid+1,treeHighIndex,2*treeIndex+2,segmentTree);
    return gcd(leftGCD,rightGCD)%MOD;
}

void printSegmentTree(ll* segMent_value,ll elements){
    for(ll i=0;i<4*elements+3;i++)
        cout<<segMent_value[i]<<" ";
    cout<<endl;
}
int main(){
    // cout<<"Going for input"<<endl;
    ll elements,queries;
    cin>>elements>>queries;
    ll* array = new ll[elements];
    for(int i=0;i<elements;i++)
        cin>>array[i];
    segMent_value = new ll[4*elements+3];
    buildTree(0,elements-1,0,array,segMent_value);
    // printSegmentTree(segMent_value,elements);
    while(queries-->0){
        ll leftIndex,rightIndex;
        cin>>leftIndex>>rightIndex;
        cout<<queryTree(leftIndex-1,rightIndex-1,0,elements-1,0,segMent_value)<<endl;
    }
    delete[] segMent_value;
}
