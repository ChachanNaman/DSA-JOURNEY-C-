#include <iostream>
#include <queue>
using namespace std;

class heap
{
public:
    int arr[100];
    int size;
    heap()
    {
        arr[0] = -1;
        size = 0;
    }
    void insert(int val)
    {
        size = size + 1;
        int index = size;
        arr[index] = val;

        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
            }
            else
            {
                return;
            }
        }
    }
    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void deletefromHeap()
    {
        if (size == 0)
        {
            cout << "nothing to delete" << endl;
            return;
        }
        arr[1] = arr[size]; // swap
        size--;             // delete last node
        int i = 1;
        while (i < size)
        {
            int leftindex = 2 * i;
            int rightindex = 2 * i + 1;
            if (leftindex < size && arr[i] < arr[leftindex])
            {
                swap(arr[i], arr[leftindex]);
                i = leftindex;
            }
            else if (rightindex < size && arr[i] < arr[rightindex])
            {
                swap(arr[i], arr[rightindex]);
                i = rightindex;
            }
            else
            {
                return; // sab sahi hai
            }
        }
    }
};

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    // check left and right of largest passed
    if (left <= n && (arr[largest] < arr[left]))
    {
        largest = left;
    }
    if (right <= n && (arr[largest] < arr[right]))
    {
        largest = right;
    }

    if (largest != i)
    { // if largest is updated from i to something else
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest); // call again to check subtree of largest updated node
    }
}

void heapsort(int arr[], int n){
    int size = n;
    while(size>1){
        //swap first
        swap(arr[size], arr[1]);
        //reduce last item from aaray as it is already sorted 
        size--;
        //now heapify remaning 
        heapify(arr, size,1);
    }
}
int main()
{

    //have to inclue first queue library
    //default priority queue is Max Heap 

    priority_queue<int> pq;   //it is max heap
    pq.push(5);
    pq.push(2);
    pq.push(4);
    pq.push(1);
    pq.push(3);

    cout<<"Top element : "<<pq.top()<<endl;  //will give largest element , as on top of max heap is largest 
    pq.pop();
    cout<<"Top element : "<<pq.top()<<endl;


cout<<endl; 

    priority_queue<int, vector<int> , greater<int> > minheap;

    minheap.push(5);
    minheap.push(2);
    minheap.push(4);
    minheap.push(1);
    minheap.push(3);

    cout<<"Top element : "<<minheap.top()<<endl;  //will give largest element , as on top of max heap is largest 
    minheap.pop();
    cout<<"Top element : "<<minheap.top()<<endl;
}