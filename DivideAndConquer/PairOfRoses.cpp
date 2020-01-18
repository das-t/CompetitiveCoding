#include <iostream>
#define MAX 1000005
using namespace std;

// Deepak has limited amount of money which he can spend on his girlfriend. 
// So he decided to buy two roses for her. Since roses are of varying sizes, 
// their prices are different. Deepak wishes to completely spend that fixed 
// amount of money on buying roses. As he wishes to spend all the money, he 
// should choose a pair of roses whose prices when summed up are equal to the 
// money that he has. Help Deepak choose such a pair of roses for his 
// girlfriend. NOTE: If there are multiple solutions print the solution that 
// minimizes the difference between the prices i and j. After each test 
// case you must print a blank line.

int main(){
    int testCases;
    cin>>testCases;
    while(testCases--){
        int* array = new int[MAX];
        for(int i=0;i<MAX;i++)
            array[i] = 0;
        int elements;
        cin>>elements;
        for(int i=0;i<elements;i++){
            int index;
            cin>>index;
            array[index]++;
        }
        int totalPrice;
        cin>>totalPrice;
        for(int i=totalPrice/2;i>=0;i--){
            if(array[i]>0){
                array[i]--;
                if(array[totalPrice-i]>0){
                    cout<<"Deepak should buy roses whose prices are "<<i<<
                        " and "<<(totalPrice-i)<<"."<<endl;
                    break;
                }
                array[i]++;
            }
        }
        delete[] array;
    }
}