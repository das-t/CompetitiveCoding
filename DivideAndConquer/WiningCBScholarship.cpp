#include <iostream>
#define ll long long int
using namespace std;

// Prateek Bhaiya decided to give 100% scholarships to the needy students by taking 
// an admission test. However in order to avoid any losses at the institute, he came 
// up with a solution. Coding Blocks has N students and M discount coupons. A student 
// will get 100% waiver if he gets X discount coupons.
// However in order to get more discount coupons in addition to those M , Bhaiya decided 
// that some students who perform badly in the admission tests, need to pay additional
// amount equivalent to Y discount coupons, i.e. good students earn discount coupons and 
// weak students need to pay coupons to get admission.
// Find out the maximum number of students who can get 100% waiver in their admission 
// fees. Note : Bhaiya will try his best to give 100% discount to maximum students possible.

bool checkPossible(ll waived_students,ll students,ll discout_coupouns,ll coupouns_per_waiver,
            ll bad_coupons){
    ll requiredCoupons = waived_students*coupouns_per_waiver;
    ll coversionBadCoupouns = bad_coupons*(students-waived_students);
    if(requiredCoupons<=discout_coupouns+coversionBadCoupouns)
        return true;
    else
        return false;
}

ll modifiedBinSearch(ll students,ll discout_coupouns,ll coupouns_per_waiver,ll bad_coupons){
    ll low=0,high=students;
    while(low<high){
        // cout<<"low:"<<low<<" high:"<<high<<endl;
        ll mid = (low+high)/2;
        if(low==high-1 && checkPossible(high,students,discout_coupouns,coupouns_per_waiver,bad_coupons))
            return high;
        else if(low==high-1)
            return low;
        else if(checkPossible(mid,students,discout_coupouns,coupouns_per_waiver,bad_coupons))
            low = mid;
        else
            high=mid;
    }
    return low;
}

int main(){
    ll students,discout_coupouns,coupouns_per_waiver,bad_coupons;
    cin>>students>>discout_coupouns>>coupouns_per_waiver>>bad_coupons;
    cout<<modifiedBinSearch(students,discout_coupouns,coupouns_per_waiver,bad_coupons)<<endl;
}