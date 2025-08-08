// TC = O(m*n)
// SC = O(m)   m = col size
// dp[i][j] depending on i+1
// curr row and next row -> 2d array of both
// soo dp[i]->curr row & dp[i+1]->next row

// User function Template for C++

class Solution {
  public:
    
    int solveSC(vector<vector<int>>& mat, int& maxi){
        //from bottom to up now
        int row = mat.size();
        int col = mat[0].size();
        
        //creating 2d array for both curr and next
        vector<int> curr(col+1,0);
        vector<int> next(col+1,0);
        
        for(int i = row-1 ; i>=0 ; i--){
            for(int j = col -1 ; j>=0 ; j--){
                    int right = curr[j+1];
                    int diagonal = next[j+1];
                    int down = next[j];
                    
                    //wherever ans -> make it dp[i][j]
                    if(mat[i][j]==1){
                        curr[j] = 1+min(right, min(diagonal , down));
                        maxi = max(maxi , curr[j]);
                    }
                    else{
                        curr[j]=0;
                    }
            }
            next = curr; //shifting
        }
        return next[0];  //return next , coz curr is next now at the end
    }
    
    int maxSquare(vector<vector<int>>& mat) {
        int maxi = 0;
        solveSC(mat , maxi);
        return maxi;
    }
};