#include <iostream>
#include <vector>
using namespace std;


int main(){
//index-> 0 1 2 3 4 5 6 7 8 9 - - 
//       {0,1,1,2,3,5,8,13,-,-,-,}  Fibonacci series

    int n;
    cout<<"Enter the Fibonacci no. you want : ";
    cin>>n;

    //step-1
    //creating vector or array to store values -> memoization
    vector<int> dp(n+1);  //gave size of n+1 coz indexing from 0

    //step-2
    dp[0]=0;
    dp[1]=1;

    //step-3
    for(int i =2; i <= n ; i++){
        dp[i] = dp[i-1]+dp[i-2];
    }

    cout<<"Fibonacci Number is : "<<dp[n];
    cout<<endl;

    return 0;
}