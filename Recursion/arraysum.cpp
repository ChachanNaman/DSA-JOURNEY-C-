#include <iostream>
using namespace std;

int arraysum(int *arr , int size){
    if(size==0){
        return 0;
    }
    return arr[0] + arraysum(arr + 1, size - 1);
}
int main(){
    int arr[5]= {1,2,3,4,5};
    int size = 5;

    int ans = arraysum(arr , size);

    cout<<ans<<endl;

    return 0;
}