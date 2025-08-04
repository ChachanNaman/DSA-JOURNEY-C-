//hello
class Solution {
public:

    int solveTab(int n , vector<int>& days, vector<int>& costs){
        vector<int>dp(n+1 , INT_MAX); //int_max coz we taking minimum
        //dp[i] = minimum cost to cover from days[i] to the end.
        dp[n] = 0; //if last element reached then return 0
        //n = 6 and dp[6]=0 base case
        for(int k = n-1 ; k >= 0 ; k--){//n-1 means k = 5 soo i can solve with k+1 coz ik dp[6] = 0;
            //1-Day pass
        int option1 = costs[0] + dp[k+1];
        
        //7-Days pass
        int i;
        for( i = k ; i<n && days[i]<days[k]+7;i++);
        int option2 = costs[1] + dp[i];

        //30-Days pass
        for( i = k  ; i < n && days[i]<days[k]+30; i++);
        int option3 = costs[2] + dp[i];

        dp[k] = min(option1, min(option2, option3));
        }
        return dp[0];
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        return solveTab(n , days , costs);
    }

};