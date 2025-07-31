#include <iostream>
#include <vector>
using namespace std;

int Spaceopt(int n){
    int prev2 = 0;
    int prev1 = 1;

    for(int i = 3 ; i <= n ; i++){
        int first=  prev1;
        int second = prev2;

        int sum = first +second;
        int ans = (i-1)*sum;

        prev2=prev1;
        prev1 = ans;
    }
    return prev1;
}


int main(){
    int n = 6;
   cout << "Number of derangements for " << n << " is: " << Spaceopt(n) << endl;
return 0;
}