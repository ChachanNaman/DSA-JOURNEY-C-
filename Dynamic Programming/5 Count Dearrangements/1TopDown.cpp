#include <iostream>
#include <vector>
using namespace std;

int solveMem(int n , vector<int> &dp){
    if(n==1){
        return 0;//no dearrangements {0}
    }
    if(n==2){
        return 1; //only one dearr {0,1}->{1,0}
    }

    if(dp[n]!= -1){
        return dp[n];
    }
    dp[n] = (n-1)*(solveMem(n-1,dp)+solveMem(n-2,dp));

    return dp[n];

}


int main(){
    int n = 3;
    vector<int> dp(n+1,-1);
   cout << "Number of derangements for " << n << " is: " << solveMem(n, dp) << endl;
return 0;
}