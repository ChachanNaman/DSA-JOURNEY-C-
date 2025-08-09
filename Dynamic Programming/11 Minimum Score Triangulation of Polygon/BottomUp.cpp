class Solution
{
public:
    int solveTab(vector<int> &values)
    {
        int n = values.size();
        vector<vector<long long>> dp(n, vector<long long>(n, 0));

        // bottom up soo start from last
        // to start j -> j should be i+2 coz . . . only 3 vertex can form
        // triangle ,there is no point to start j from i+1
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i + 2; j < n; j++)
            { // j >= i+2 means at least 3 vertices
                long long ans = LLONG_MAX;
                for (int k = i + 1; k < j; k++)
                {
                    long long left = dp[i][k];
                    long long right = dp[k][j];
                    long long cost =
                        (long long)values[i] * values[j] * values[k] + left +
                        right;
                    ans = min(ans, cost);
                }
                dp[i][j] = ans;
            }
        }
        return (int)dp[0][n - 1];
    }

    int minScoreTriangulation(vector<int> &values)
    {

        int n = values.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        return solveTab(values);
    }
};