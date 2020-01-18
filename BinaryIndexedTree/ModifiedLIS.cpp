#include <iostream>
#include <vector>
#define ll long long int
using namespace std;

void updateWeight(ll index,ll value,ll* array,ll elements){
    // cout<<"went for updaet"<<endl;
    for(ll i=index;i<=elements;i+=(i&-i))
        array[i] += value;
    // cout<<"update dpone" <<endl;
}

ll queryWeight(ll index,ll* array){
    ll totalSum = 0;
    for(ll i=index;i>0;i-=(i&-i))
        totalSum += array[i];
    return totalSum;
}

ll modifiedLIS(ll* array,ll* weight,ll elements){
    ll* lisArray = new ll[elements+1];
    ll* weightArray = new ll[elements+1];
    for(ll i=0;i<=elements;i++){
        lisArray[i] = 0;
        weightArray[i] = 0;
    }
    ll maxTotalWeight=0,currentTotalWeight=0;
    ll length = 1;
    for(ll i=1;i<=elements;i++){
        int index = lower_bound(lisArray+1,lisArray+length,array[i])-lisArray;
        lisArray[index] = array[i];
        // cout<<"while updating reducing value by "<<(queryWeight(index,weightArray)-queryWeight(index-1,weightArray))<<endl;
        updateWeight(index,weight[i]-(queryWeight(index,weightArray)-queryWeight(index-1,weightArray)),weightArray,elements);
        if(index==length)
            length++;
        currentTotalWeight = queryWeight(index,weightArray);

        cout<<"index found: "<<index<<" and len:"<<length<<endl;
        cout<<"total sum: "<<queryWeight(index,weightArray)<<endl;
        // cout<<"negat sum: "<<queryWeight(index+1,weightArray)<<endl;
        // cout<<"current weight:"<<currentTotalWeight<<endl;
        if(currentTotalWeight>maxTotalWeight)
            maxTotalWeight = currentTotalWeight;
        // cout<<"done index"<<index<<" "<<maxTotalWeight<<endl;
    }
    // cout<<"outsided loop:"<<maxTotalWeight<<endl;
    delete[] lisArray;
    delete[] weightArray;
    return maxTotalWeight;
}

int main(){
    int testCases;
    cin>>testCases;
    while(testCases-->0){
        int elements;
        cin>>elements;
        ll* array = new ll[elements+1];
        ll* weight = new ll[elements+1];
        array[0] = weight[0] = 0;
        for(int i=1;i<=elements;i++)
            cin>>array[i];
        for(int i=1;i<=elements;i++)
            cin>>weight[i];
        ll res8lt = modifiedLIS(array,weight,elements);
        cout<<res8lt<<endl;
        delete[] array;
        delete[] weight;
    }
}