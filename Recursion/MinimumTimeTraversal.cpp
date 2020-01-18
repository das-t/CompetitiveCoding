#include <iostream>
using namespace std;

// A robot is moving on co-ordinate axis. Time taken to move from one point 
// to another point is equal to the Manhattan Distance. Starting Point (S) 
// and Ending Point (E) of the robot is fixed. There are n wormhole like 
// pipelines also on the coordinate axis. Time taken to move from one point 
// to another point of each pipeline is given. Robot can use those pipelines 
// to move from statring point to ending point. Find the minimum time required 
// during traversal.

int manhattenCost(int,int,int,int);

int minCost(int index,int currX,int currY,int startX,int startY,int** cost,bool* used,int elements){
    if(index<0)
        return manhattenCost(currX,currY,startX,startY);
    else{
        int minValue = minCost(index-1,currX,currY,startX,startY,cost,used,elements);
        for(int i=0;i<elements;i++)
            if(!used[i]){
                used[i] = true;
                minValue = min(minValue,manhattenCost(currX,currY,cost[i][2],cost[i][3])+cost[i][4]+
                    minCost(index-1,cost[i][0],cost[i][1],startX,startY,cost,used,elements));
                int currVal = manhattenCost(currX,currY,cost[i][2],cost[i][3])+cost[i][4]+
                    minCost(index-1,cost[i][0],cost[i][1],startX,startY,cost,used,elements);
                minValue = min(minValue,manhattenCost(currX,currY,cost[i][0],cost[i][1])+cost[i][4]+
                    minCost(index-1,cost[i][2],cost[i][3],startX,startY,cost,used,elements));
                currVal = manhattenCost(currX,currY,cost[i][0],cost[i][1])+cost[i][4]+
                    minCost(index-1,cost[i][2],cost[i][3],startX,startY,cost,used,elements);
                used[i] = false;
            }
        return minValue;
    }
}

int manhattenCost(int startX,int startY,int destX,int destY){
    return abs(startX-destX)+abs(startY-destY);
}

int main(){
    int testCases;
    cin>>testCases;
    for(int i=1;i<=testCases;i++){
        int elements;
        cin>>elements;
        int startx,starty,endx,endy;
        cin>>startx>>starty>>endx>>endy;
        int** array = new int*[elements];
        for(int i=0;i<elements;i++){
            array[i] = new int[5];
            cin>>array[i][0]>>array[i][1]>>array[i][2]>>array[i][3]>>array[i][4];
        }
        bool* used = new bool[elements];
        for(int i=0;i<elements;i++)
            used[i] = false;
        cout<<"#"<<i<<" : "<<minCost(elements-1,endx,endy,startx,starty,array,used,elements)<<endl;
    }   
};