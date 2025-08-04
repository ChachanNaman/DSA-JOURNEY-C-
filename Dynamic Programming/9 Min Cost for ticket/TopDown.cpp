class Solution {
public:

    int solveMem(int n ,vector<int>& days, vector<int>& costs, int index , vector<int> &dp){
        if(index>=n){
            return 0;
        }

        if(dp[index]!= -1){
            return dp[index];
        }

        //1-Day pass
        int option1 = costs[0] + solveMem(n , days , costs , index+1, dp);

        //7-Days pass
        int i;
        for(i= index ; i<n && days[i]<days[index]+7;i++);
        int option2 = costs[1] + solveMem(n , days , costs , i,dp);

        //30-Days pass
        for( i = index  ; i < n && days[i]<days[index]+30; i++);
        int option3 = costs[2] + solveMem(n , days, costs , i,dp);

        dp[index] = min(option1, min(option2, option3));

        return dp[index];
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int>dp(n+1, -1);
        int index = 0;
        return solveMem(n  , days , costs , index, dp);
    }
};