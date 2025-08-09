// User function Template for C++

class Solution {
  public:
  
    int solve(vector<vector<int>>& mat, int i , int j , int& maxi, vector<vector<int>>& dp){
        if(i>=mat.size() || j>=mat[0].size()){
            return 0;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int right = solve(mat , i , j+1 , maxi,dp);
        int diagonal = solve(mat , i+1 , j+1, maxi,dp);
        int down = solve(mat , i+1 , j , maxi,dp);
        
        //wherever ans -> make it dp[i][j]
        if(mat[i][j]==1){
            dp[i][j] = 1+min(right, min(diagonal , down));
            maxi = max(maxi , dp[i][j]);
            return dp[i][j];
        }
        else{
            return dp[i][j]=0;
        }
    }
    int maxSquare(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> dp(n ,vector<int>(m , -1) );
        int maxi = 0;
        solve(mat , 0 , 0 , maxi ,dp);
        return maxi;
    }
};

[ 1, 0, 1
  1, 1, 1
  1, 1, 1
]