class Solution {
public:
    int solveTab(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> dp(n,0);
        dp[0] = nums[0];

        for (int i = 1; i < n; i++) {
            int incl = nums[i] + dp[i - 2];
            int excl = dp[i - 1]+0;
            dp[i] = max(incl, excl);
        }

        return dp[n - 1];
    }

    int rob(vector<int>& nums) {
        return solveTab(nums);
    }
};
