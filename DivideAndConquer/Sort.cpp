#include <iostream>
#define ll long long int
using namespace std;

void merge(ll low,ll mid,ll high,ll* array){
    ll* barr = new ll[high+1];
    ll i=low,j=mid+1,k=low;
    while(i<=mid && j<=high)
        if(array[i]<=array[j])
            barr[k++] = array[i++];
        else
            barr[k++] = array[j++];
    if(i<=mid)
        while(i<=mid)
            barr[k++] = array[i++];
    else
        while(j<=high)
            barr[k++] = array[j++];
    for(ll i=low;i<=high;i++)
        array[i] = barr[i];
    delete[] barr;
}

void mergeSort(ll low,ll high,ll* array){
    if(low<high){
        ll mid = (low+high)/2;
        mergeSort(low,mid,array);
        mergeSort(mid+1,high,array);
        merge(low,mid,high,array);
    }
}

void printArray(ll* array,ll elements){
    for(ll i=0;i<elements;i++)
        cout<<array[i]<<" ";
    cout<<endl;
}

int main(){
    ll elements;
    cin>>elements;
    ll* array = new ll[elements];
    for(ll i=0;i<elements;i++)
        cin>>array[i];
    mergeSort(0,elements-1,array);
    printArray(array,elements);
    delete[] array;
}