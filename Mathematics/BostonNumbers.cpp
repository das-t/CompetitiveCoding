#include <iostream>
#include <cmath>
using namespace std;

// A Boston number is a composite number, the sum of whose digits is the 
// sum of the digits of its prime factors obtained as a result of prime 
// factorization (excluding 1 )

long long int digitSum(long long int number){
    long long int sum = 0;
    while(number>0){
        sum += number%10;
        number /= 10;
    }
    return sum;
}

long long int sumOfPrimeDivisors(long long int number){
    long long int sum = 0;
    while((number&1)==0){
        number >>= 1;
        sum += 2;
    }
    long long int maxValue = sqrt(number);
    for(long long int i=3;i<maxValue;i+=2){
        if(number%i==0){
            int primeDigitSum = digitSum(i);
            while(number%i==0){
                number /= i;
                sum += primeDigitSum;
            }
        }
    }
    if(number>2)
        sum += digitSum(number);
    return sum;
}

int main(){
    long long int number;
    cin>>number;
    if(digitSum(number)==sumOfPrimeDivisors(number))
        cout<<"1"<<endl;
    else
        cout<<"0"<<endl;
}