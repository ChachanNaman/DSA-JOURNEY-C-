#include <iostream>
#include <vector>
using namespace std;

void selection_sort(int arr[] ,vector<int> ans ){
    for(int i = 0 ; i<6; i++){
        int minindex = i;
        for(int j = i+1 ; j< 6; j++){
            if(arr[minindex]>arr[j]){
                minindex = j;  //update the min index with new minimumn if found after i+1
            }
        }
        swap(arr[minindex], arr[i]);
    }
    for(int i = 0 ;i < 6;i++ ){
        ans.push_back(arr[i]);
    }
}
int main(){
    int arr[6] = {12, 33 , 44, 31, 10,11};
    vector<int> ans;
    selection_sort(arr, ans);
    for(int i = 0 ;i < 6;i++ ){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}