#include <iostream>
#include <vector>
using namespace std;

void bubble_sort(int arr[] ,vector<int> ans ){
    for(int i = 1 ; i<6; i++){
        //for round 1 to n-1
        for(int j = 0 ; j<6-i; j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
    for(int i = 0 ;i < 6;i++ ){
        ans.push_back(arr[i]);
    }
}
int main(){
    int arr[6] = {12, 33 , 44, 31, 10,11};
    vector<int> ans;
    bubble_sort(arr, ans);
    for(int i = 0 ;i < 6;i++ ){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}