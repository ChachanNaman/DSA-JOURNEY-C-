#include <iostream>
using namespace std;

int solvemem(int n, int x, int y, int z, vector<int> &dp)
{

    if (n == 0)
    {
        return 0;
    }
    if (n < 0)
    {
        return INT_MIN;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    int a = solvemem(n - x, x, y, z, dp) + 1;
    int b = solvemem(n - y, x, y, z, dp) + 1;
    int c = solvemem(n - z, x, y, z, dp) + 1;

    dp[n] = max(a, max(b, c));

    return dp[n];
}

int solvetab(int n , int x  , int y, int z){
    vector<int> dp(n+1 , INT_MIN); //doint int_min coz to protect if -1+1= 0
    dp[0]=0;

    for(int i = 1 ; i <=n ; i++){
        if(i-x>= 0){
            dp[i] = max(dp[i], dp[i-x] +1);
        }
        if(i-y>= 0){
            dp[i] = max(dp[i], dp[i-y] +1);
        }
        if(i-z>= 0){
            dp[i] = max(dp[i], dp[i-z] +1);
        }
    }

    if(dp[n]< 0){
        return 0;
    }
    else{
        return dp[n];
    }
}
int main()
{
    int n = 7;
    int x = 5, y = 2, z = 2;

    vector<int> dp(n + 1, -1);
    // int ans = solvemem(n, x, y, z, dp);
    int ans = solvetab(n , x, y, z);
    if (ans < 0)
        ans = 0;

    cout << "Maximum number of cuts: " << ans << endl;

    return 0;
}

/*

Let’s Trace the Table
Start:

dp[0] = 0
dp[1 to 7] = INT_MIN
i = 1:
1 - 5, 1 - 2, 1 - 2 → all < 0 → skip

Nothing changes.

i = 2:
2 - 5 → no

2 - 2 = 0 → dp[0] = 0 → dp[2] = max(INT_MIN, 0 + 1) = 1

✅ dp[2] = 1

i = 3:
3 - 2 = 1 → dp[1] = INT_MIN → invalid

dp[3] remains INT_MIN

i = 4:
4 - 2 = 2 → dp[2] = 1 → dp[4] = max(INT_MIN, 1 + 1) = 2

✅ dp[4] = 2

i = 5:
5 - 5 = 0 → dp[0] = 0 → dp[5] = max(INT_MIN, 0 + 1) = 1

5 - 2 = 3 → dp[3] = INT_MIN → skip

✅ dp[5] = 1

i = 6:
6 - 2 = 4 → dp[4] = 2 → dp[6] = max(INT_MIN, 2 + 1) = 3

✅ dp[6] = 3

i = 7:
7 - 2 = 5 → dp[5] = 1 → dp[7] = max(INT_MIN, 1 + 1) = 2

✅ dp[7] = 2

Final dp[] Table:

Index:  0  1   2   3   4   5   6   7
dp:     0  -∞  1  -∞  2   1   3   2
📤 Return Value


if(dp[n] < 0) return 0;
else return dp[n];
So, for n = 7, the final answer is dp[7] = 2.

This means you can make 2 cuts from length 7 using only pieces of size 5, 2, and 2.

E.g., one valid way: 5 + 2

*/