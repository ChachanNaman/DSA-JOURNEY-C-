#include <iostream>
using namespace std;

int Spaceopt(vector<int> weight, vector<int> value, int n , int capacity ){

   //if i see dp[i] is depending all on dp[i-1] curr row on prev row , soo why to make dp just make two vector of it
   vector<int> prev(capacity+1, 0);   //1-d array
   vector<int> curr(capacity+1, 0);
    for(int w = weight[0] ; w <= capacity ; w++){
        if(weight[0] <= capacity){
            prev[w] = value[0];
        }
        else{
            prev[w]= 0;
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
                include = value[index] + prev[w-weight[index]]; //w-weight[1] = 2-2 =0 , 3-2 =1....
            }
            int exclude = 0 +prev[w]; 
            //curr[w] will be updated after getting max of both at every w
            curr[w] = max(include , exclude);//lastly update the dp with max of both
            
        }
        //after making curr[w] suppose 2nd row is curr and 1st was prev , then for moving to 3rd row i have to update prev from 1st row to 2nd row
        prev = curr;
    }
    //after exiting the loop my prev will be at the last row soo i can directly say prev[5] is the ans coz prev keep updated to latest curr 
    return prev[capacity];  //last value in matrix return that 


}
int main(){
    vector<int> weight = {1,2,4,5};
    vector<int> value= {5,4,8,6};

    int n = 4;
    int maxweight = 5;

    int a = Spaceopt(weight , value , n , maxweight );

    cout<<a<<endl;
}

/*
Base Case : 
Now:
weight[0] = 1
value[0] = 5

So, for w >= 1, you can take item 0:
prev = [0, 5, 5, 5, 5, 5]

After item 0 (already handled):
prev = [0, 5, 5, 5, 5, 5]
✅ index = 1 (item 1 → weight = 2, value = 4)
Looping from w = 0 to 5:

w	Include?	include	  exclude = prev[w]	 curr[w]
0	❌	           0        	0	          0
1	❌	           0	        5	          5
2	✅ 4 + prev[0] = 4 + 0 = 4	5	          5
3	✅ 4 + prev[1] = 4 + 5 = 9	5          	  9
4	✅ 4 + prev[2] = 4 + 5 = 9	5	          9
5	✅ 4 + prev[3] = 4 + 5 = 9	5	          9

Now:
curr = [0, 5, 5, 9, 9, 9]
prev = curr
✅ index = 2 (item 2 → weight = 4, value = 8)
w	Include?	include	exclude = prev[w]	curr[w]
0	❌            0             0	          0 
1	❌            0             5              5
2	❌            0             5           	  5
3	❌	         0             9              9
4	✅ 8 + prev[0] = 8 + 0 = 8  9	          9
5	✅ 8 + prev[1] = 8 + 5 = 13	9	          13

Now:
curr = [0, 5, 5, 9, 9, 13]
prev = curr
✅ index = 3 (item 3 → weight = 5, value = 6)
w	Include?	include	 exclude = prev[w]	 curr[w]
0	❌	          0	            0	            0
1	❌	          0	            5	            5
2	❌	          0	            5	            5
3	❌	          0            	9           	9
4	❌             0          	9           	9
5	✅ 6 + prev[0] = 6 + 0 = 6	13          	13

Final:
curr = [0, 5, 5, 9, 9, 13]
So prev[5] = 13

✅ Final Answer:

return prev[capacity] = 13;
🎯 Maximum value you can carry in knapsack = 13

*/
