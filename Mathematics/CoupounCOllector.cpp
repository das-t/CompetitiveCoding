#include <iostream>
#include <cstdio>
using namespace std;

// BuggyD loves to carry his favorite die around. Perhaps you wonder why 
// it's his favorite? Well, his die is magical and can be transformed 
// into an N-sided unbiased die with the push of a button. Now BuggyD 
// wants to learn more about his die, so he raises a question:
// What is the expected number of throws of his die while it has N sides 
// so that each number is rolled at least once?

double expectedScratch(int coupouns){
    double result = 0;
    for(int i=1;i<=coupouns;i++){
        result += ((double)1/(coupouns-i+1));
    }
    result *= coupouns;
    return result;
}

int main(){
    int testCases;
    cin>>testCases;
    while(testCases-->0){
        int number;
        cin>>number;
        // cout<<expectedScratch(number)<<endl;
        printf("%.2f\n",expectedScratch(number));
    }
}