class Solution {
public:

    int solveMem(vector<int>& values , int i , int j , vector<vector<int>> &dp){
        if(i+1==j){ //Base Case
            //means only two vertex is there then i+1=j
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int ans = INT_MAX;
        //for loop for k can be anywhere in polygon , soo k to traverse all
        for(int k=i+1 ; k<j ; k++){//where k starts from i+1(start) and should  be in j(end point)
            ans = min(ans , values[i]*values[j]*values[k]+solveMem(values ,i ,k,dp)+solveMem(values ,k, j, dp));
            //i to k and k to j -> k in place of j firstly , k in place of i secondly
        }
        dp[i][j] = ans;
        return dp[i][j];
    }

    int minScoreTriangulation(vector<int>& values) {

        int n = values.size();

        //as i and j changing with loop , soo have to replace with 2D Matrix
        vector<vector<int>> dp(n , vector<int>(n ,-1));
        return solveMem(values , 0 , n-1 , dp);

    }

};