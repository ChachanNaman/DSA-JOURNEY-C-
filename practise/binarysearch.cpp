#include <iostream>
using namespace std;
bool binary(int arr[], int s, int e, int key)
{
    if (s > e)
    {
        return false;
    }
    int mid = s + (e - s) / 2;
    if (key == arr[mid])
    {
        return true;
    }
    if (arr[mid] < key)
    {
        return binary(arr, mid + 1, e, key);
    }
    else
    {
        return binary(arr, s, mid - 1, key);
    }
}
int main()
{

    int arr[6] = {34, 55, 12, 90, 12, 78};
    int size = 6;

    bool ans = binary(arr, 0, 6, 34);
    if (ans)
    {
        cout << "found" << endl;
    }
    else
    {
        cout << "not found" << endl;
    }

    return 0;
}