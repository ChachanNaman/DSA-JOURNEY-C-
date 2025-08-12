class Solution {
public:
    // Recurssive
    // int solve(vector<int>& satis, int index , int time){
    //     //Base Case
    //     if(index == satis.size()){
    //         return 0;//last index reached then backtrack by returning 0
    //     }

    //     int include = satis[index]*(time+1) + solve(satis , index+1, time+1);
    //     int exclude = 0 + solve(satis , index+1, time);//time remains same 

    //     return max(include , exclude);
    // }

    //Top-Down(Memoization)
    // int solveMem(vector<int>& satis, int index , int time , vector<vector<int>> &dp){
    //     //Base Case
    //     if(index == satis.size()){
    //         return 0;
    //     }

    //     if(dp[index][time] != -1){
    //         return dp[index][time];
    //     }

    //     int include = satis[index]*(time+1) + solveMem(satis , index+1, time+1,dp);
    //     int exclude = 0 + solveMem(satis , index+1, time,dp);//time remains same 
    //     dp[index][time] = max(include , exclude);
    //     return dp[index][time];
    // }

    //Bottom-Up
    int solveTab(vector<int>& satis){
        int n = satis.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, 0));//handles base case also by initialising 0 at n and n+1

        for(int index = n-1 ; index>=0 ; index--){
            for(int time = index ; time>=0; time--){
                int include = satis[index]*(time+1) + dp[index+1][time+1];
                int exclude = 0+ dp[index+1][time];

                dp[index][time] = max(include , exclude);
            }
        }
        return dp[0][0];
    }

    //Space Opt -> O(n)
    int solveSO(vector<int>& satis){
        int n = satis.size();
        
        vector<int> curr(n+1,0);
        vector<int>next(n+1,0);

        for(int index = n-1 ; index>=0 ; index--){
            for(int time = index ; time>=0; time--){
                int include = satis[index]*(time+1) + next[time+1];
                int exclude = 0+ next[time];

                curr[time] = max(include , exclude);
            }
            next = curr;
        }
        return next[0];
    }

    
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin() , satisfaction.end());
        // return solve(satisfaction, 0 , 0);

        // int n = satisfaction.size();
        // vector<vector<int>>dp(n+1 , vector<int>(n+1,-1));
        // return solveMem(satisfaction , 0 , 0 , dp);

        // return solveTab(satisfaction);

        return solveSO(satisfaction);
    }
};