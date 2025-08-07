#include <iostream>
using namespace std;
int solveMem(vector<int>&arr , int target ,vector<int> &dp){
    if(target==0){
        return 1;
    }
    if(target < 0){
        return 0;
    }

    if(dp[target] != -1){
        return dp[target];
    }
    int ans = 0;
    for(int i = 0 ; i < arr.size() ; i++){
    ans = ans + solveMem(arr , target - arr[i] , dp );
    }
    dp[target] = ans;
    return dp[target];
}

int main(){
    vector<int>arr = {1, 2 , 5};
    int target = 5;
    vector<int>dp(target+1,-1);
    int ans = solveMem(arr , target ,dp);
    cout<<ans<<endl;
}

/*

Base Case:
If you hit exact target (e.g., used numbers and reduced target to 0), that’s a valid way, so return 1

Invalid Case**:
- If you overshoot target (e.g., target = -1), return 0 (invalid path).








*/