#include <iostream>
using namespace std;

void merge(int *arr, int s , int e){
    int mid = s+(e-s)/2;
    int len1= mid - s +1;
    int len2 = e-mid;
    int *first = new int[len1];
    int *second = new int[len2];

    int mainindex = s;
    for(int i = 0 ; i<len1 ; i++){
        first[i]= arr[mainindex++];
    }
    mainindex = mid +1;
    for(int i = 0 ; i<len2 ; i++){
        second[i]= arr[mainindex++];
    }

    int index1= 0;
    int index2= 0;
    mainindex = s;

    while(index1 <len1 && index2 <len2){
       if(first[index1]< second[index2]){
        arr[mainindex++] = first[index1++];
       }

       else{
        arr[mainindex++] = second[index2++];
       }

    }
    while(index1 <len1){
        arr[mainindex++] = first[index1++];
    }
    while(index2 <len2){
        arr[mainindex++] = second[index2++];
    }
    
}
void mergesort(int *arr, int s , int e ){

    if(s>= e){
        return ;
    }
    int mid = s+(e-s)/2;

    mergesort(arr, s, mid -1);
    mergesort(arr, mid, e);

    merge(arr, s, e);
}
int main(){
    return 0;
}