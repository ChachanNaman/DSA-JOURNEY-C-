#include <iostream>
using namespace std;

int fibonacci(int n ){
    if(n==0){//base
        return 0;
    }
    if(n==1){//base
        return 1;
    }

   int ans =  fibonacci(n-1)+ fibonacci(n-2);
    return ans;

}

int main(){
    int n;
    cout<<"Give index : ";
    cin>>n;


    int ans = fibonacci(n);

    cout<<ans<<endl;
}