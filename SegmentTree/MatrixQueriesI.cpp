#include <iostream>
#define ll long long int
using namespace std;
int modValue=1000000007;

// Mike has N 2*2 matrices, M1, M2, …, Mn. Elements of matrices are in range [0,r-1], 
// where r is an integer. Mike considers an operation, o, such that A2x2 o B2x2 = (A2x2 * B2x2)%r 
// (each value in the product of 2 matrices is stored modulo r). Mike gives you q queries, each 
// of the form L,R. For each query, you have to find ML o ML+1 o … o MR.
// Note that it is not necessary, that all the input matrices are invertible. For eg. 
// a matrix, A2x2=[[0,0],[0,0]] can be present in input.

class Matrix{
public:
    ll a,b;
    ll c,d;

    Matrix(){
        Matrix(0,0,0,0);
    }

    Matrix(ll a,ll b,ll c,ll d){
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
    }

    void printMatrix(){
        cout<<a<<" "<<b<<endl<<c<<" "<<d<<endl;
    }

    static Matrix getIdentity(){
        return Matrix(1,0,0,1);
    }

    static void multiplyMatrix(Matrix A,Matrix B,Matrix& C){
        C.a = (A.a * B.a + A.b * B.c)%modValue;
        C.b = (A.a * B.b + A.b * B.d)%modValue;
        C.c = (A.c * B.a + A.d * B.c)%modValue;
        C.d = (A.c * B.b + A.d * B.d)%modValue;
    }
};


class SegmentTree{
    Matrix* tree;
    ll elements;

    void buildTree(ll low,ll high,ll treeIndex,Matrix* array){
        // cout<<"low:"<<low<<" high:"<<high<<endl;
        if(low==high){
            tree[treeIndex] = array[low];
            return;
        }
        ll mid = (low+high)/2;
        buildTree(low,mid,2*treeIndex+1,array);
        buildTree(mid+1,high,2*treeIndex+2,array);
        tree[treeIndex] = Matrix::getIdentity();
        Matrix::multiplyMatrix(tree[2*treeIndex+1],tree[2*treeIndex+2],tree[treeIndex]);
    }

    Matrix query(ll low,ll high,ll treeLowIndex,ll treeHighIndex,ll treeIndex){
        if(treeLowIndex>high || treeHighIndex<low)
            return Matrix::getIdentity();
        else if(low<=treeLowIndex && treeHighIndex<=high)
            return tree[treeIndex];
        ll mid = (treeLowIndex+treeHighIndex)/2;
        Matrix matA = query(low,high,treeLowIndex,mid,2*treeIndex+1);
        Matrix matB = query(low,high,mid+1,treeHighIndex,2*treeIndex+2);
        Matrix matC = Matrix::getIdentity();
        Matrix::multiplyMatrix(matA,matB,matC);
        return matC;
    }
public:
    SegmentTree(Matrix* array,ll elements){
        this->elements = elements;
        tree = new Matrix[4*elements+3];
        buildTree(0,elements-1,0,array);
    }

    Matrix query(ll leftIndex,ll rightIndex){
        return query(leftIndex,rightIndex,0,elements-1,0);
    }
};

int main(){
    int elements,queries;
    cin>>modValue>>elements>>queries;
    Matrix* array = new Matrix[elements];
    for(int i=0;i<elements;i++){
        ll a,b,c,d;
        cin>>a>>b>>c>>d;
        array[i].a=a%modValue;
        array[i].b=b%modValue;
        array[i].c = c%modValue;
        array[i].d =d%modValue;
    }
    SegmentTree segmentTree(array,elements);
    while(queries-->0){
        ll leftIndex,rightIndex;
        cin>>leftIndex>>rightIndex;
        Matrix result = segmentTree.query(leftIndex-1,rightIndex-1);
        result.printMatrix();
        cout<<endl;
    }
}