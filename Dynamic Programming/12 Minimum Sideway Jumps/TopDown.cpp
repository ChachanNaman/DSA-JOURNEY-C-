class Solution {
public:

    int solveMem(vector<int>& obstacles, int currlane , int pos, vector<vector<int>>& dp){
        int n = obstacles.size()-1; //last position
        if(pos == n){//Base Case(if start = end then no jump)
            return 0;
        }

        if(dp[currlane][pos] != -1){
            return dp[currlane][pos];
        }
        if(obstacles[pos+1] != currlane){//obstacles[pos+1] gives lane where obs is like obstacles[1] = 3 means at position 1 obstacle is in 3 lane
            return solveMem(obstacles , currlane , pos+1,dp);//just move frog in curr lane , means no obstacle there in current path
        }
        else{//obstacle there in current path
            //i have to get minimum jump also like suppose if both up and down jump can happen soo i have to get minimum out of it soo using minimum
            int ans = INT_MAX;
            for(int i = 1 ; i<=3 ; i++){
                if(currlane != i && obstacles[pos] != i){
                    //means current lane should not be continued for jump
                    //and obstacle shouldn't be there at that lane
                    ans = min(ans , 1+solveMem(obstacles , i , pos,dp));
                }
            }
            dp[currlane][pos] = ans;
            return dp[currlane][pos];
        }
    }

    int solveTab(vector<int>& obstacles){
        int n = obstacles.size()-1;
        vector<vector<int>> dp(4, vector<int>(n ,0));

        //Base Case initialse in dp (last nth meet is return 0)
        dp[0][n]=0;
        dp[1][n]=0;
        dp[2][n]=0;
        dp[3][n]=0;
        for(int pos = n-1; pos>=0 ; pos--){
            for(int lane = 1 ; lane<=3 ; lane++){
                
            }
        }
    }

    int minSideJumps(vector<int>& obstacles) {

        //i can see position is changing by +1 and current lane too by i
        //soo clearly i can see 2D DP needed
        //row should be 4 considering 0,1,2,3 and cols should be = obs
        vector<vector<int>>dp(4, vector<int>(obstacles.size(), -1));
        return solveMem(obstacles , 2, 0 , dp);
    }
};