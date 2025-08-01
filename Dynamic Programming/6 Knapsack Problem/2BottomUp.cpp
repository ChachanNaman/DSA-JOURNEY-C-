#include <iostream>
using namespace std;

int solveTab(vector<int> weight, vector<int> value, int n , int capacity ){

    //creating vector of like rows= index like n = 4 then 4 rows
    //and columns is capacity+1 like capacity is 5 then columns will be 6 coz 0 1 2 3 4 5 
    vector<vector<int>>dp(n , vector<int>(capacity+1, 0));

    //initialising Base Case (only 0th item)
    //dealing with 0th row only
    //Item 0: weight = 1, value = 5
    //So for all w >= 1, we can include item 0 → value = 5
    /*
    Update dp[0][w]:

    w →   0   1   2   3   4   5
    i
    ↓
    0        0   5   5   5   5   5
    1        0   0   0   0   0   0
    2        0   0   0   0   0   0
    3        0   0   0   0   0   0
*/
    for(int w = weight[0] ; w < capacity ; w++){
        if(weight[0] <= capacity){
            dp[0][w] = value[0];
        }
        else{
            dp[0][w]= 0;
        }
    }

    // Fill Remaining Rows
    for(int index = 1 ;  index < n ; index++){//have to start with 1st row , as 0th row initialised 
        for(int w = 0 ;  w<= capacity ; w++ ){
            int include = 0;
            /*
            weight = {1,2,4,5}    index 1 = 2 , index 2 = 4 
            values = {5,4,8,6}  
            */
            if(weight[w]<= w){//we are checking like w wise 2<0cant 2<1cant 2<=2after 2 i can include 
                include = value[index] + dp[index-1][w-weight[index]]; //w-weight[1] = 2-2 =0 , 3-2 =1....
            }
            int exclude = 0 +dp[index-1][w]; //prev row and w going on(column) to match with prev row values
        
            dp[index][w] = max(include , exclude);//lastly update the dp with max of both
            //final updation of dp matrix here 
            //dp[1][w] =max(include, exclude);
        }
    }
    return dp[n-1][capacity];  //last value in matrix return that 


}
int main(){
    vector<int> weight = {1,2,4,5};
    vector<int> value= {5,4,8,6};

    int n = 4;
    int maxweight = 5;

    int a = solveTab(weight , value , n-1 , maxweight );

    cout<<a<<endl;
}

/*
i = 1 (Item 1: weight = 2, value = 4)

For w = 0 to 5, we calculate:
include = value[1] + dp[0][w - weight[1]];
exclude = dp[0][w];
dp[1][w] = max(include, exclude);

w	Can Include?  Include	 Exclude = dp[0][w]	   dp[1][w] = max(include , exclude)
0	❌	            0	             0	              0
1	❌	            0	             5             	  5
2	✅	 4 + dp[0][0] = 4 + 0 = 4	 5	              5
3	✅	 4 + dp[0][1] = 4 + 5 = 9	 5	              9
4	✅	 4 + dp[0][2] = 4 + 5 = 9	 5	              9
5	✅	 4 + dp[0][3] = 4 + 5 = 9	 5	              9

Update table:

    w →   0   1   2   3   4   5
i
↓
0        0   5   5   5   5   5
1        0   5   5   9   9   9
2        0   0   0   0   0   0
3        0   0   0   0   0   0

i = 2 (Item 2: weight = 4, value = 8)
w	Can Include?	Include	Exclude = dp[1][w]	dp[2][w]
0	❌	              0	            0	            0
1	❌	              0            	5           	5
2	❌	              0	            5	            5
3	❌	              0          	9           	9
4	✅   8 + dp[1][0] = 8 + 0 = 8	9	            9
5	✅	8 + dp[1][1] = 8 + 5 = 13	9	           13

Update table:

    w →   0   1   2   3   4   5
i
↓
0        0   5   5   5   5   5
1        0   5   5   9   9   9
2        0   5   5   9   9  13
3        0   0   0   0   0   0


🔁 i = 3 (Item 3: weight = 5, value = 6)
w	Can Include?	Include	Exclude = dp[2][w]	dp[3][w]
0	❌               	0         	0	           0
1	❌                	0        	5              5
2	❌                	0	        5              5
3	❌                	0        	9	           9
4	❌                	0	        9	           9
5	✅	 6 + dp[2][0] = 6 + 0 = 6	13	           13

Update final table:

    w →   0   1   2   3   4   5
i
↓
0        0   5   5   5   5   5
1        0   5   5   9   9   9
2        0   5   5   9   9  13
3        0   5   5   9   9  13


✅ Final Answer:
return dp[n-1][capacity] = dp[3][5] = 13
🎯 Maximum Value: 13

*/
