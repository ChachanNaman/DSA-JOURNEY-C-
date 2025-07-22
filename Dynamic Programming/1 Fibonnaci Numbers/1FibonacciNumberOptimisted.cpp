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
    int prev1 = 1;
    int prev2 = 0;

    //step-2
    for(int i = 2 ; i<=n ; i++){
        int curr = prev1 +prev2;
        prev2= prev1;  //shifting
        prev1 = curr;
    }

    //step-3
    cout<<"Fibonacci Number is : "<<prev1;
    cout<<endl;

    return 0;
}