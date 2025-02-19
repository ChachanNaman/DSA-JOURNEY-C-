#include <iostream>
using namespace std;
int binarysearch(int arr[], int size, int key)
{
    int start = 0;
    int end = size - 1;
    int mid = start + (end - start) / 2;
    while (start <= end)
    {
        if (key == arr[mid])
        {
            return mid;
        }
        if (key > arr[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return -1;
}
int main()
{
    int even[6] = {1,2,4,5,7,8};
    // int odd[5] = {98, 24, 57, 82, 27};
    int evenindex = binarysearch(even, 6, 7);
    cout << " 44 is at index : " << evenindex << endl;
    return 0;
}