#include <iostream>
using namespace std;
// bool ispresent(int arr[][4], int target , int n , int m){
// for (int i = 0; i < 3; i++)
//     {
//         for (int j = 0; j < 4; j++)
//         {
//            if(arr[i][j]==target){
//             return 1;

//            }
//         }
//     }
//     return 0;
// }
// to print sum row vise
// void printsum(int arr[][4], int n, int m)
// {
//     for (int i = 0; i < 3; i++)
//     {
//         int sum = 0;
//         for (int j = 0; j < 4; j++)
//         {

//             sum += arr[i][j];
//         }
//         cout << sum << " " << endl;
//     }
// }
// to print sum column vise 
void printsum(int arr[][4], int n, int m)
{
    for (int j = 0; j < 4; j++)
    {
        int sum = 0;
        for (int i = 0; i < 3; i++)
        {

            sum += arr[i][j];
        }
        cout << sum << " " << endl;
    }
}
int main()
{
    int arr[3][4];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    // cout<<"enter the element to search :  "<<endl;
    // int target;
    // cin>>target;
    // if(ispresent(arr, target , 3,4)){
    //     cout<<"element found"<<endl;

    // }
    // else {
    //     cout<<"element not found "<<endl;
    // }
    printsum(arr, 3, 4);
    return 0;
}