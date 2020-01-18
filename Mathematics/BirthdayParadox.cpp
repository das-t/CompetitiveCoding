#include <iostream>
using namespace std;

// Your task is simple, determine the minimum number of people 
// required in the room so that two have same birthday with 
// probability greater than or equal to 'p'. (Assume there are 
// 365 days in every year)

int getPersons(double probability){
    if(probability>=1)
        return 366;
    double currentProb = 1;
    int persons = 1;
    while(1-currentProb<probability){
        persons++;
        currentProb = currentProb*(365-persons+1)/365;
    }
    return persons;
}

int main(){
    double prob;
    cin>>prob;
    cout<<getPersons(prob)<<endl;
}