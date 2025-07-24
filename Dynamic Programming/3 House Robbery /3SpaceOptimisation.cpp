class Solution {
public:
    int solveopt(vector<int>& nums){
        int n = nums.size();
        
        int prev2 = 0;  //out of domain then return 0
        int prev1 = nums[0];  //only 1st element there in it

        for(int i = 1 ; i < n ; i++){
            int incl = prev2 + nums[i];
            int excl = prev1 + 0;
            int ans = max(incl , excl);
            prev2=prev1;
            prev1=ans;
        }

        return prev1;

    }
    int rob(vector<int>& nums) {
        return solveopt(nums);
    }
};

/*
 Let's Use This Example:
cpp
Copy
Edit
nums = [2, 7, 9, 3, 1]
Means:

House 0 has ₹2

House 1 has ₹7

House 2 has ₹9

House 3 has ₹3

House 4 has ₹1

You can't rob adjacent houses.

🔁 Dry Run of the Code:
Initial:

prev2 = 0         // money robbed till i-2
prev1 = nums[0] = 2 // money robbed till i-1 (only first house)
Now iterate from i = 1 to 4 (rest of the houses):

i = 1:
incl = prev2 + nums[1] = 0 + 7 = 7  // rob house 1
excl = prev1 = 2                   // skip house 1
ans = max(7, 2) = 7

Now update:
prev2 = prev1 = 2
prev1 = ans = 7

i = 2:
incl = prev2 + nums[2] = 2 + 9 = 11  // rob house 2
excl = prev1 = 7                    // skip house 2
ans = max(11, 7) = 11

Update:
prev2 = prev1 = 7
prev1 = ans = 11

i = 3:
incl = prev2 + nums[3] = 7 + 3 = 10
excl = prev1 = 11
ans = max(10, 11) = 11

Update:
prev2 = prev1 = 11
prev1 = ans = 11

i = 4:
incl = prev2 + nums[4] = 11 + 1 = 12
excl = prev1 = 11
ans = max(12, 11) = 12

Update:
prev2 = prev1 = 11
prev1 = ans = 12

✅ Final Return:

return prev1; // which is 12
🧮 Final Answer: 12
Rob house 0 (2) + house 2 (9) + house 4 (1) = 12

OR
Rob house 1 (7) + house 4 (1) + house 2 (skip) = less than 12

*/