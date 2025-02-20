#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
class island
{
public:
int survival(int s , int n , int m) {  //m=max food req to survive , n = no. of food shop giving each day , s = survival days
 int sunday = s/7;
 int days = s-sunday;
 int total = s*m;
 int ans = 0;
 if(total%n==0){
    ans = total/n;
 }
 else{
    ans= total/n+1;
 }
 if(ans<=days){
    return ans;
 }
 else{return -1;}
}
};
int main(){
    island a;
    
    int s =10;
    int n= 16;
    int m =2 ;

    cout << "food refilled :  " << a.survival(s,n,m) << endl;
    
    return 0;
}