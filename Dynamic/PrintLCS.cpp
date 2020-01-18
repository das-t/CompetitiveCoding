#include <iostream>
using namespace std;

string printLCS(int** memorize,int rows,int cols,string str1,string str2){
    int length = memorize[rows-1][cols-1];
    string result = string(length,'x');
    int i = rows-1,j=cols-1;
    while(i>0 && j>0){
        if(memorize[i][j]==memorize[i-1][j])
            i--;
        else if(memorize[i][j]==memorize[i][j-1])
            j--;
        else{
            result.at(length-1) = str1.at(i);
            i--;j--;length--;
        }        
    }
    if(length>0)
        if(i==0)
            result.at(length-1) = str1.at(0);
        else
            result.at(length-1) = str2.at(0);
    return result;
}

void lcs(string str1,string str2){
    int** memorize = new int*[str1.length()];
    for(int i=0;i<str1.length();i++){
        memorize[i] = new int[str2.length()];
        for(int j=0;j<str2.length();j++)
            memorize[i][j] = 0;
    }
    for(int i=0;i<str2.length();i++)
        if(str2.at(i)==str1.at(0))
            memorize[0][i] = 1;
        else if(i>=1)
            memorize[0][i] = memorize[0][i-1];
    for(int i=0;i<str1.length();i++)
        if(str1.at(i)==str2.at(0))
            memorize[i][0] = 1;
        else if(i>=1)
            memorize[i][0] = memorize[i-1][0];
    for(int i=1;i<str1.length();i++)
        for(int j=1;j<str2.length();j++)
            if(str1.at(i)==str2.at(j))
                memorize[i][j] = memorize[i-1][j-1] + 1;
            else
                memorize[i][j] = max(memorize[i-1][j],memorize[i][j-1]);
    
    // for(int i=0;i<str1.length();i++){
    //     for(int j=0;j<str2.length();j++)
    //         cout<<memorize[i][j]<<" ";
    //     cout<<endl;
    // }
    // cout<<memorize[str1.length()-1][str2.length()-1]<<endl;
    cout<<printLCS(memorize,str1.length(),str2.length(),str1,str2)<<endl;
    for(int i=0;i<str1.length();i++)
        delete[] memorize[i];
    delete[] memorize;
}
int main(){
    string str1,str2;
    cin>>str1>>str2;
    lcs(str1,str2);
}