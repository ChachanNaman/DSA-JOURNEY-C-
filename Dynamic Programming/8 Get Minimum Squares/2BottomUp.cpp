#include <iostream>
using namespace std;

int solveTab(int n){
    vector<int> dp(n+1, INT_MAX);
    dp[0]=0;

    for(int i = 1 ; i <= n ; i++){//We're calculating dp[1], dp[2], ..., dp[n] one by one
                                  //Each i means: "What is the minimum number of squares needed to make sum = i
        for(int j = 1; j*j<=n ; j++){//
            if(i-j*j>=0){
                dp[i] = min(dp[i], 1+dp[i-j*j]);
            }   
        }
    }
    return dp[n];
}

int main(){
    int n;
    cout<<"Enter the number you want min perfect square of : ";
    cin>>n;

    int ans = solveTab(n);

    cout<<ans<<endl;
}