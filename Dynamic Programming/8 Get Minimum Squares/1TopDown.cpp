#include <iostream>
using namespace std;

int solveMem(int n , vector<int> &dp){
    if(n==0){ //Base case: If n == 0, it means no squares are needed. So return 0.
        return 0;
    }

    if(dp[n] != -1){
        return dp[n];
    }

    int ans = n;
    for(int i = 1 ; i*i <= n ; i++){
        // Try all perfect squares ≤ n.
        //i*i will be: 1, 4, 9, 16, ... ≤ n
        ans = min(ans , 1+solveMem(n-i*i , dp));  
        //Take this one square, then compute the answer for the remaining part"
    }   

    dp[n] =ans;
    return dp[n];
}

int main(){
    int n;
    cout<<"Enter the number you want min perfect square of : ";
    cin>>n;

    vector<int>dp(n+1 , -1);

    int ans = solveMem(n , dp);

    cout<<ans<<endl;
}