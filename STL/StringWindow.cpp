#include <iostream>
using namespace std;

int hashArray[1024];
int hashCopy[1024];
 
// Ravi has been given two strings named string1 and string 2.
// He is supposed to find the minimum length substring of the
// string1 which contains all the characters of string2. Help
// him to find the substring

bool checkHashEquals(){
    for(int i=0;i<1024;i++)
        if(hashCopy[i]<hashArray[i])
            return false;
    return true;
}

void createHash(string str){
    for(int i=0;i<1024;i++)
        hashArray[i] = 0;
    for(int i=0;i<str.size();i++)
        hashArray[str.at(i)]++;
}

void clearHash(int* hashArr){
    for(int i=0;i<1024;i++)
        hashArr[i] = 0;
}

int main(){
    string str1,str2;
    getline(cin,str1);
    getline(cin,str2);
    createHash(str2);
    for(int i=str2.length();i<=str1.length();i++){
        clearHash(hashCopy);
        int j = 0;
        for(;j<i-1;j++)
            hashCopy[str1.at(j)]++;
        for(;j<str1.length();j++){
            hashCopy[str1.at(j)]++;
            if(checkHashEquals()){
                cout<<str1.substr(j-i+1,i)<<endl;
                return 0;
            }
            hashCopy[str1.at(j-i+1)]--;
        }
    }
    cout<<"No string"<<endl;
}