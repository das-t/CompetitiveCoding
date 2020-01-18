#include <iostream>
using namespace std;


int main(){
    long long int index;
    cin>>index;
    long long int catalynVal = 1;
    for(int i=0;i<index;i++){
        catalynVal *= 2*(2*i+1);
        catalynVal /= (i+2);
    }
    cout<<catalynVal<<endl;
}