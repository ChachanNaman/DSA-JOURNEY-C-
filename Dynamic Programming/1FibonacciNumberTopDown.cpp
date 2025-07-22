#include <iostream>
#include <vector>
using namespace std;

int fibo(int n , vector<int> &dp){
  
    if(n==0 || n==1){ //base case
        return n;
    }

    if(dp[n]!= -1){
        return dp[n];  //if number already found then return that number 
    }

    dp[n] = fibo(n-1, dp)+fibo(n-2, dp);

    return dp[n];
}

int main(){
//index-> 0 1 2 3 4 5 6 7 8 9 - - 
//       {0,1,1,2,3,5,8,13,-,-,-,}  Fibonacci series

    int n;
    cout<<"Enter the Fibonacci no. you want : ";
    cin>>n;

    //creating vector or array to store values -> memoization
    vector<int> dp(n+1);  //gave size of n+1 coz indexing from 0

    for(int i = 0 ; i <= n;i++){
        dp[i] = -1;  //initialising my array with -1
    }

    int ans = fibo(n , dp);
    cout<<"Fibonacci Number is : "<<ans;
    cout<<endl;

    return 0;
}