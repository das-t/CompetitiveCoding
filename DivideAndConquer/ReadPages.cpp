#include <iostream>
#define ll long long int
using namespace std;

// You are given N books, ith of which has Pi pages (Pi <= Pj, if i < j).
// You have to assign these N books to M students, such that each student 
// has subsegment of books and the maximum number of pages assigned to a 
// student is minimized. You have to find the maximum number of pages, 
// a student can have in this assignment of books.

ll getSumOfElements(ll*,ll);
bool checkPage(ll,ll*,ll,ll);

ll modifiedBinSearch(ll* array,ll elements,ll students){
    ll low=array[elements-1],high=getSumOfElements(array,elements);
    while(low<high){
        ll mid = (low+high)/2;
        if(low==high-1 && checkPage(low,array,elements,students))
            return low;
        else if(low==high-1)
            return high;
        else if(checkPage(mid,array,elements,students))
            high = mid;
        else
            low = mid;
    }
    return low;
}

bool checkPage(ll pages,ll* array,ll elements,ll students){
    ll currSum = 0;
    students--;
    for(ll i=0;i<elements;i++){
        if(currSum+array[i]<=pages)
            currSum += array[i];
        else if(students==0)
            return false;
        else {
            currSum = array[i];
            students--;
        }
    }
    return true;
}

ll getSumOfElements(ll* array,ll elements){
    ll totalSum = 0;
    for(ll i=0;i<elements;i++)
        totalSum += array[i];
    return totalSum;
}

int main(){
    ll elements,students;
    cin>>elements>>students;
    ll* array = new ll[elements];
    for(ll i=0;i<elements;i++)
        cin>>array[i];
    cout<<modifiedBinSearch(array,elements,students)<<endl;
    delete[] array;
}