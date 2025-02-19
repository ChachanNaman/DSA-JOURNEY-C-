#include <iostream>
using namespace std;

int partition(int arr[], int s, int e){
    int pivot = arr[s];
    int cnt = 0; 
    for(int i =s+1; i<=e; i++){    //for loop to count element less than pivot
        if(arr[i]< pivot){
            cnt++;
        }
    }
    int pivotindex = s+cnt;      
    swap(arr[pivotindex], arr[s]);  //swapping pivot for partition

    int i =s;
    int j =e;

    while(i<pivotindex && j>pivotindex){   //traversing i++ and j-- until equal to pivotindex
        while(arr[i]<= pivot){
            i++;
        }
        while(arr[j]> pivot){
            j--;
        }
        if(i<pivotindex && j>pivotindex){
            swap(arr[i++] , arr[j--]);       //swap the elements vioalting this
        }
    }
    return pivotindex;


}
void quicksort(int arr[], int s, int e)
{
    //base case
    if(s>=e){
        return;
    }
    //making partition
    int p = partition(arr, s,e);
    //recursive call
    quicksort(arr, s,p-1);
    quicksort(arr, p+1,e);
}

int main()
{
    int arr[6] = {4, 6, 2, 5, 1, 3};
    int n = 6;
    quicksort(arr,0, n-1);
    for(int i = 0 ; i<n; i++){
        cout<< arr[i]<< " ";
    }
    cout<<endl;
    return 0;
}