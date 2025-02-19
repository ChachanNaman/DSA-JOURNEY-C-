#include <iostream>
using namespace std;

int firstocc(int arr[], int size, int key)
{
    int s = 0;
    int e = size - 1;
    int m = s + (e - s) / 2;
    int ans = -1;
    while (s <= e)
    {
        if (arr[m] == key)
        {
            ans = m;
            e = m - 1;
        }
        else if (arr[m] < key)
        {
            s = m + 1;
        }
        else if (arr[m] > key)
        {
            e = m - 1;
        }
        m = s + (e - s) / 2;
    }
    return ans;
}
int lastocc(int arr[], int size, int key)
{
    int s = 0;
    int e = size - 1;
    int m = s + (e - s) / 2;
    int ans = -1;
    while (s <= e)
    {
        if (arr[m] == key)
        {
            ans = m;
            s = m + 1;
        }
        else if (arr[m] < key)
        {
            s = m + 1;
        }
        else if (arr[m] > key)
        {
            e = m - 1;
        }
        m = s + (e - s) / 2;
    }
    return ans;
}
int main()
{
    int even[6] = {1, 2, 2, 2, 2, 9};
    cout << "first occ of 2 is at index : " << firstocc(even, 6, 2) << endl;
    cout << "last occ of 2 is at index : " << lastocc(even, 6, 2) << endl;
    cout << "total number of occ is " << (lastocc(even, 6, 2) - firstocc(even, 6, 2)) + 1 << endl;
    return 0;
}