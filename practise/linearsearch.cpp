#include <iostream>
using namespace std;

bool linearsearch(int arr[], int size , int k){
    if (size == 0){
        return false;
    }
    if(arr[0]== k){
   return true;
    }
    else {
        bool remaining = linearsearch(arr+1, size-1,k);
        return remaining;
    }
}
int main(){
    int arr[]={2,4,6,13,66};
    int size = 5;
    int k = 13;
    bool ans = linearsearch(arr, size, k);
   if(ans){
    cout<<"present"<<endl;
   }
   else{
    cout<<"absent"<<endl;
   }

    return 0;
}