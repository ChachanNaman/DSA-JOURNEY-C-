#include <iostream>
using namespace std;

int solveTab(vector<int> &arr, int target)
{
    vector<int> dp(target + 1, 0);

    dp[0] = 1; // Base Case

    for (int i = 1; i <= target; i++)  // i -> 1 ,2,3 ,4 ,5
    { 
        for (int j = 0; j < arr.size(); j++) // j -> 1 , 2, 5
        { 
            if (i - arr[j] >= 0)
            { // agar mera target - arr ka koi number krke +ve aaraha hai toh he consider karu
                dp[i] = dp[i] + dp[i - arr[j]]; // i is traversing target thats why i-arr[i]
            }
        }
    }
    return dp[target];
}

int main()
{
    vector<int> arr = {1, 2, 5};
    int target = 5;
    int ans = solveTab(arr, target);
    cout << ans << endl;
}

/*
i=1 ke lie j apna pura loop chalayenge arr[j] -> 1 ,2, 5 -> 1-1, 1-2, 1-5
1-1 = 0 -> dp[1] = dp[1] + dp[1-1] -> dp[1] = 0+1 = 1
dp[1] = 1 -> dp =[1,1,0,0,0,0]

i=2 ke lie j apna pura loop chalayenge arr[j] -> 2-1 , 2-2 , 2-5
2-1 = 1 dp[1]=1(calculated) -> 2-2=0 dp[0]=1(base case) 
dp[2] = dp[2] + dp[2-1] -> dp[2] = 0 + dp[1] -> dp[2] = 0+1 = 1
-> dp[2] = dp[2] + dp[2-2] -> dp[2] = 1 + dp[0] = 1+1 -> dp[2] = 2
dp[2] = 2 -> dp = [1, 1, 2, 0, 0, 0]
Ways to make 2:
1+1
2

i=3 ke lie j apna pura loop chalayenge arr[j] -> 3-1 , 3-2 , 3-5
3-1 = dp[2]=2(calculate) -> 3-2 = dp[1]=1(calculated) 
dp[3]=dp[3] + dp[3-1] -> dp[3] = 0+dp[2] -> dp[3] = 0+2 = 2
dp[3]=dp[3] + dp[3-2] -> dp[3] = 2 + dp[1] = 2+1 = 3
dp[3]=3 -> dp = [1, 1, 2, 3, 0, 0]
Ways to make 3:
1+1+1
1+2
2+1

i=4 ke lie j apna pura loop chalayenge arr[j] -> 4-1, 4-2 , 4-5
4-1 = dp[3]=3(calc) -> 4-2 = dp[2]=2(calc) 
dp[4] = dp[4]+dp[4-1] -> dp[4]=0+3 = 3
dp[4] = dp[4]+dp[4-2] -> dp[4]=3+2 = 5
dp[4]=5 -> dp = [1, 1, 2, 3, 5, 0]

i=5 ke lie j apna pura loop chalayenge arr[j] -> 5-1, 5-2, 5-5
5-1=dp[4]=5(calc) -> 5-2=dp[3]=3(calc) -> 5-5=dp[0]=0(Base Case)
dp[5]=dp[5]+dp[5-1] -> dp[5]=0+5=5
dp[5]=dp[5]+dp[5-2] -> dp[5]=5+3=8
dp[5]=dp[5]+dp[5-5] -> dp[5]=8+1=9

return dp[target] = dp[5] = 9   Answer


*/