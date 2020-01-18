#include <iostream>
#define ll long long int
using namespace std;

// Deepak loves to travel but he wants to minimize the total travel expenditure.
// His journey will be through N checkpoints. Checkpoints are numbered from 0 to
// N−1. At the start of his journey he is present at the checkpoint 0. Also
// checkpoint N−1 will lead to his final destination. Each checkpoint has a petrol
// pump which can be used to fill petrol in the car. Now cost of petrol per litre
// at different checkpoints is given by array C which has 0-based indexing where
// C[i] is the cost per litre of petrol at the ith checkpoint. Note that there is
// an infinite amount of supply at each checkpoint and car tank is also of infinite
// capacity. Now another array L is given which has 0-based indexing where L[i]
// denotes the amount of petrol in litres required to reach the (i+1)th checkpoint
// from the ith checkpoint. Note that the extra petrol remaining in the tank does
// not vanishes after reaching a checkpoint. Also, Deepak should have atleast L[i]
// litres of petrol at each checkpoint in order to reach the next checkpoint. Help
// Deepak to estimate the minimum cost required in order complete the journey.

int main(){
    int testCases;
    cin>>testCases;
    while(testCases-->0){
        ll elements;
        cin>>elements;
        ll* cost = new ll[elements];
        for(ll i=0;i<elements;i++)
            cin>>cost[i];
        ll* petrol = new ll[elements];
        for(ll i=0;i<elements;i++)
            cin>>petrol[i];
        ll totalCost = petrol[0]*cost[0];
        ll currentMinCost = cost[0];
        for(ll i=1;i<elements;i++){
            currentMinCost = min(currentMinCost,cost[i]);
            totalCost += currentMinCost*petrol[i];
        }
        cout<<totalCost<<endl;
        delete[] cost;
        delete[] petrol;
    }
}