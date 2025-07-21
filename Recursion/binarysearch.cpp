#include <iostream>
using namespace std;
bool binary(int *arr , int s, int e , int key){
    if(s>e){//base case
        return false;
    }
    int mid = s+(e-s)/2;

    if(arr[mid]==key){
        return true;
    }
    if(arr[mid]<key){
        return binary(arr , mid+1 , e , key);
    }
    else{
        return binary(arr , s , mid -1 , key);
    }
}

int main(){

    int arr[8] = {1,2,3,4,5,6,7,8};
    int size = 8;
    int key;
    cout<<"enter key to search from {1,2,3,4,5,6,7,8} : ";
    cin>>key;
   
    bool ans = binary(arr ,0 , 7, key);
     cout<<endl;
    if(ans == 1){
        cout<<"found"<<endl;
    }
    else{
        cout<<"not found"<<endl;
    }

    return 0;
}