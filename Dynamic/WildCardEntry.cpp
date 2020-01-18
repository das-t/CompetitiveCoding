#include <iostream>
using namespace std;

int wildCardEntry(int index1,int index2,string str1,string str2,int** memorize){
    if(index1<0 && index2<0)
        return 1;
    else if(index1<0 || index2<0)
        return 0;
    else if(memorize[index1][index2]!=-1)
        return memorize[index1][index2];
    else if(str1.at(index1)==str2.at(index2) || str2.at(index2)=='?'){
        memorize[index1][index2] = wildCardEntry(index1-1,index2-1,str1,str2,memorize);
        return memorize[index1][index2];
    }
    else if(str2.at(index2)=='*'){
        int result = 0;
        for(int i=index1;i>=-1;i--)
            result = max(result,wildCardEntry(i,index2-1,str1,str2,memorize));
        memorize[index1][index2] = result;
        return memorize[index1][index2];
    }
    else
        return 0;
}

int main(){
    string str1,str2;
    cin>>str1>>str2;
    int** memorize = new int*[str1.length()];
    for(int i=0;i<str1.length();i++){
        memorize[i] = new int[str2.length()];
        for(int j=0;j<str2.length();j++)
            memorize[i][j] = -1;
    }
    if(wildCardEntry(str1.length()-1,str2.length()-1,str1,str2,memorize)==1)
        cout<<"MATCHED"<<endl;
    else
        cout<<"NOT MATCHED"<<endl;
}