#include <iostream>
#include <algorithm>
#define ll long long int
using namespace std;

// A religious king wants to build the largest temple in his kingdom. To
// build the largest temple he needs to find the area of the largest
// suitable land . Given co-ordinates which denotes rivers flowing through
// the point horizontally as well as vertically , find the largest area
// possible to make the grand temple.

ll getMaxDiff(ll* array,ll elements){
    ll maxDiff = array[0];
    for(ll i=1;i<elements;i++)
        maxDiff = max(maxDiff,array[i]-array[i-1]-1);
    maxDiff = max(maxDiff,elements-array[elements-1]-1);
    return maxDiff;
}

int main(){
    ll elements;
    cin>>elements;
    ll* xElements = new ll[elements];
    ll* yElements = new ll[elements];
    for(ll i=0;i<elements;i++)
        cin>>xElements[i]>>yElements[i];
    sort(xElements,xElements+elements);
    sort(yElements,yElements+elements);
    ll x_maxDiff = getMaxDiff(xElements,elements);
    ll y_maxDiff = getMaxDiff(yElements,elements);
    ll maxArea = x_maxDiff*y_maxDiff;
    cout<<maxArea<<endl;
    delete[] xElements;
    delete[] yElements;
}