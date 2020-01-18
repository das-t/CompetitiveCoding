#include <iostream>
#define ll long long int
#define MOD 1000000007
using namespace std;

// IMPORTANT CONCEPT

// You are climbing up using stairs where a number is written on each stair.
// At each step we define the alpha score as sum of all the numbers previously
// seen on the stairs which are smaller than the present number. Alpha score
// of the whole journey is defined as the sum of all the alpha scores at each
// step. Print the alpha score of whole journey modulus 1000000007.

ll mergeAlphaScore(ll low,ll mid,ll high,ll* array){
    ll alphaScore = 0;
    ll i=low,j=mid+1,k=low;
    ll* barr = new ll[high+1];
    ll* cumul = new ll[high+1];
    for(ll x=low;x<=high;x++)
        if(x==low)
            cumul[x] = array[x]%MOD;
        else
            cumul[x] = (cumul[x-1]+array[x]+MOD)%MOD;
    while(i<=mid && j<=high)
        if(array[i]<array[j])
            barr[k++] = array[i++];
        else{
            if(i>low)
                alphaScore = (alphaScore+cumul[i-1])%MOD;
            barr[k++] = array[j++];
        }
    if(i<=mid)
        while(i<=mid)
            barr[k++] = array[i++];
    else
        while(j<=high){
            if(i>low)
                alphaScore = (alphaScore+cumul[i-1])%MOD;
            barr[k++] = array[j++];
        }
    for(int i=low;i<=high;i++)
        array[i] = barr[i];
    delete[] barr;
    delete[] cumul;
    return alphaScore;
}

ll countAlphaScore(ll low,ll high,ll* array){
    ll alphaScore = 0;
    if(low<high){
        ll mid = (low+high)/2;
        alphaScore = (alphaScore+countAlphaScore(low,mid,array))%MOD;
        alphaScore = (alphaScore+countAlphaScore(mid+1,high,array))%MOD;
        alphaScore = (alphaScore+mergeAlphaScore(low,mid,high,array))%MOD;
    }
    return alphaScore;
}

int main(){
    ll elements;
    cin>>elements;
    ll* array = new ll[elements];
    for(ll i=0;i<elements;i++)
        cin>>array[i];
    cout<<countAlphaScore(0,elements-1,array)<<endl;
}