#include <iostream>
#include <vector>
using namespace std;

int bfs(int**,int,int,int,int);
pair<int,int> getUnVisitedCell(int**,int,int);
bool isValidMove(int,int,int**,int,int);

int largestPond(int** array,int rows,int cols){
    int largestPondSize = 0;
    pair<int,int> node = getUnVisitedCell(array,rows,cols);
    while(node.first!=-1 && node.second!=-1){
        int pondSize = bfs(array,node.first,node.second,rows,cols);
        if(pondSize>largestPondSize)
            largestPondSize = pondSize;
        node = getUnVisitedCell(array,rows,cols);
    }
    return largestPondSize;
}

int bfs(int** array,int rowIndex,int colIndex,int rows,int cols){
        // cout<<"got bfs for: "<<rowIndex<<","<<colIndex<<endl;
    vector<pair<int,int>> pool;
    array[rowIndex][colIndex] = 0;
    pool.push_back(make_pair(rowIndex,colIndex));
    int poolSize = 0;
    while(pool.size()>0){
        pair<int,int> node = pool.at(0);
        pool.erase(pool.begin());
        poolSize++;
        rowIndex = node.first;
        colIndex = node.second;
        // cout<<"got bfs2 for: "<<rowIndex<<","<<colIndex<<endl;
        if(isValidMove(rowIndex-1,colIndex,array,rows,cols)){
            array[rowIndex-1][colIndex] = 0;
            pool.push_back(make_pair(rowIndex-1,colIndex));
        }
        if(isValidMove(rowIndex+1,colIndex,array,rows,cols)){
            array[rowIndex+1][colIndex] = 0;
            pool.push_back(make_pair(rowIndex+1,colIndex));
        }
        if(isValidMove(rowIndex,colIndex-1,array,rows,cols)){
            array[rowIndex][colIndex-1] = 0;
            pool.push_back(make_pair(rowIndex,colIndex-1));
        }
        if(isValidMove(rowIndex,colIndex+1,array,rows,cols)){
            array[rowIndex][colIndex+1] = 0;
            pool.push_back(make_pair(rowIndex,colIndex+1));
        }
    }
    // cout<<"max poolsize: "<<poolSize<<endl;
    return poolSize;
}

pair<int,int> getUnVisitedCell(int** array,int rows,int cols){
    pair<int,int> unvisitedCell = make_pair(-1,-1);
    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++)
            if(array[i][j]==1){
                unvisitedCell = make_pair(i,j);
                return unvisitedCell;
            }
    return unvisitedCell;
}

bool isValidMove(int rowIndex,int colIndex,int** array,int rows,int cols){
    // cout<<"checking for index: "<<rowIndex<<","<<colIndex<<endl;
    if(rowIndex<0 || colIndex<0 || rowIndex>=rows || colIndex>=cols){
        // cout<<"false1"<<endl;
        return false;
    }
    else if(array[rowIndex][colIndex]==0){
        // cout<<"false2"<<endl;
        return false;
    }
    else
        return true;
}

void copyMatrix(int** array,int** matrix,int rows,int cols){
    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++)
            matrix[i][j] = array[i][j];
}

int main(){
    int rows,cols;
    cin>>rows>>cols;
    int** graph = new int*[rows];
    int** matrix = new int*[rows];
    for(int i=0;i<rows;i++){
        graph[i] = new int[cols];
        matrix[i] = new int[cols];
        for(int j=0;j<cols;j++)
            cin>>graph[i][j];
    }
    int largest = 0;
    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++)
            if(graph[i][j]==0){
                // cout<<"going for "<<i<<","<<j<<endl;
                copyMatrix(graph,matrix,rows,cols);
                matrix[i][j] = 1;
                int currentSize = largestPond(matrix,rows,cols);
                if(currentSize>largest)
                    largest = currentSize;
            }
    cout<<largest<<endl;
}

/*
5 3
1 0 0
1 1 1
0 0 0
0 1 0
0 1 0
*/