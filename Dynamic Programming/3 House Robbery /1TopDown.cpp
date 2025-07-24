class Solution {
public:
    int solveMemo(int n, vector<int>& nums, vector<int>& dp) {
        if (n == 0) return nums[0];//base case
        if (n < 0) return 0;//base case

        if (dp[n] != -1) return dp[i];//step-3

        int incl = nums[n] + solveMemo(n - 2, nums, dp);
        int excl = solveMemo(n - 1, nums, dp);
        dp[n] = max(incl, excl);   //step-2
    }
        return dp[n]; 
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1); //step-1
        return solveMemo(n - 1, nums, dp);
    }
};
