#include <iostream>
using namespace std;
bool linear(int *arr, int size ,int key){
    if(size==0){
        return false;
    }
    if(arr[0]==key){
        return true;
    }
    else{
        bool ans = linear(arr+1, size-1,key);
        return ans;
    }

}

int main(){
    int key;
    int arr[5]= {4 ,5,6,76,1};
    int size = 5;
    
    cout<<"enter key to search from {4 ,5,6,76,1} : ";
    cin>>key;
   
    bool ans = linear(arr ,size, key);
     cout<<endl;
    if(ans == 1){
        cout<<"found"<<endl;
    }
    else{
        cout<<"not found"<<endl;
    }

    return 0;
}