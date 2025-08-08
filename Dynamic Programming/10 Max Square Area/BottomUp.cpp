// TC = O(m*n)
// SC = O(m*n)

class Solution {
  public:

    int solveTab(vector<vector<int>>& mat, int& maxi){
        //from bottom to up now
        int row = mat.size();
        int col = mat[0].size();
        
        vector<vector<int>>dp(row+1 , vector<int>(col+1, 0));
        //base case inside this initialised with 0
        //to protect going out of bound did row+1 , col+1
        
        for(int i = row-1 ; i>=0 ; i--){
            for(int j = col -1 ; j>=0 ; j--){
                    int right = dp[i][j+1];
                    int diagonal = dp[i+1][j+1];
                    int down = dp[i+1][j];
                    
                    //wherever ans -> make it dp[i][j]
                    if(mat[i][j]==1){
                        dp[i][j] = 1+min(right, min(diagonal , down));
                        maxi = max(maxi , dp[i][j]);
                    }
                    else{
                        dp[i][j]=0;
                    }
            }
        }
        return dp[0][0];
    }
    
    int maxSquare(vector<vector<int>>& mat) {
        int maxi = 0;
        solveTab(mat , maxi);
        return maxi;
    }
};