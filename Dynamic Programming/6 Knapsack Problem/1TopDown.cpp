#include <iostream>
using namespace std;

int solveMem(vector<int> weight, vector<int> value, int index , int capacity , vector<vector<int>> &dp){

    //base case 
    if(index == 0){
        if(weight[0]<=capacity){
            return value[0];
        }
        else{
            return 0;
        }
    }

    if(dp[index][capacity] != -1){
        return dp[index][capacity];
    }
    int include = 0;
    
    if(weight[index]<= capacity){
        include = value[index]+solveMem(weight , value , index-1, capacity-weight[index], dp);
    }
    int exclude = 0 + solveMem(weight , value , index-1 , capacity , dp);

    dp[index][capacity] = max(exclude , include);

    return dp[index][capacity];
}
int main(){
    vector<int> weight = {1,2,4,5};
    vector<int> value= {5,4,8,6};

    int n = 4;
    int maxweight = 5;

    vector<vector<int>>dp(n , vector<int>(maxweight+1, -1));
    int a = solveMem(weight , value , n-1 , maxweight , dp);

    cout<<a<<endl;
}