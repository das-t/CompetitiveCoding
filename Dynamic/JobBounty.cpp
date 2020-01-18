#include <iostream>
using namespace std;

int maxLenSubstrParenthesis(string str){
    int* memorize = new int[str.length()];
    for(int i=0;i<str.length();i++)
        memorize[i] = 1;
    for(int i=1;i<str.length();i++)
        if(str.at(i-1)!=str.at(i))
            memorize[i] = memorize[i-1]+1;
    int maxDivisble2 = 0;
    for(int i=0;i<str.length();i++)
        if(memorize[i]%2==0 && maxDivisble2<memorize[i])
            maxDivisble2 = memorize[i];
    delete[] memorize;
    return maxDivisble2;
}

int main(){
    string str;
    cin>>str;
    cout<<maxLenSubstrParenthesis(str)<<endl;
}