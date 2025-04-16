#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

class mobileuser
{
private:
    long int m_no;
    string name;
    long int billamount;

public:

    mobileuser()
    {
        m_no = 0;
        name = "";
        billamount = 0;
    }

    friend class Records;
};
class Records
{
private:
    mobileuser M[10];
   

public:
 int n;
    Records(int n1)
    {
        n = n1;
    }
    void accept();
    void display();
    void adjust(int n1, int i);
    void heapSort();
     void quicksort(int p, int r);
    int partition(int m, int n);
    int linearSearch(long int key);
    int binarySearch_nr(long int key);

};

void Records::accept()
{
    cout<<endl;
    cout << "Enter Mobile Number , Name and Bill Amount " << endl;
    cout<<endl;
    cout << "Enter ones's data in one line giving some space "<<endl;
    cout<<endl;
    for (int i = 0; i < n; i++)
    {
        cin >> M[i].m_no >> M[i].name >> M[i].billamount;
    }
    cout<<endl;
}
void Records::display()
{
    cout << "MOBILE NUMBER | NAME | BILL AMOUNT" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << M[i].m_no << "        " << M[i].name << "        " << M[i].billamount << endl;
    }
    cout<<endl;
}

void Records::adjust(int n1, int i)
{
    int j;
    mobileuser temp;
    while ((2 * i + 1) <= n1)
    {
        j = 2 * i + 1;
        if ((j + 1 <= n1) && (M[j + 1].billamount > M[j].billamount))
            j++;
        if (M[i].billamount >= M[j].billamount)
        {
            break;
        }
        else
        {
            temp = M[i];
            M[i] = M[j];
            M[j] = temp;
            i = j;
        }
    }
}
void Records::heapSort()
{
    int i, n1 = n;
    mobileuser temp;
    for (i = (n1 / 2) - 1; i >= 0; i--)
    {
        adjust(n1 - 1, i);
    }
    while (n1 > 0)
    {
        temp = M[0];
        M[0] = M[n1 - 1];
        M[n1 - 1] = temp;
        n1--;
        adjust(n1 - 1, 0);
    }
    cout<< " After HEAP SORT -> "<<endl;
    cout<<endl;
}

void Records::quicksort(int p, int r) {
    if (p < r)
    {
        int q = partition(p, r);
        quicksort(p, q - 1);
        quicksort(q + 1, r);
    }

}

int Records::partition(int p, int r) {
    int i = p - 1;
    long int x = M[r].m_no;  

    for (int j = p; j < r; j++) {
        if (    M[j].m_no <= x) {
            i++;
            swap( M[i], M[j]);
        }
    }
    swap(M[i + 1], M[r]);
    return i + 1;

    
}


int Records::linearSearch(long int key)
{
    for (int i = 0; i < n; i++)
    {
        if (key == M[i].m_no)
        {
            cout << "Record found ! " << endl;
            cout<<endl;
            cout << "MOBILE NUMBER | NAME | BILL AMOUNT" << endl;
            cout << M[i].m_no << " " << M[i].name << " " << M[i].billamount << endl;
            return i;
        }
    }
    return -1;
}

int Records::binarySearch_nr(long int key)
{
    int low = 0, mid;
    int high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (M[mid].m_no == key)
        {
            cout << "Record found ! " << endl;
            cout<<endl;
            cout << "MOBILE NUMBER | NAME | BILL AMOUNT" << endl;
            cout << endl;
            cout << M[mid].m_no << "        " << M[mid].name << "        " << M[mid].billamount << endl;

            return mid;
        }
        else if (key < M[mid].m_no)
        {
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return -1;
}

int main()
{
    int n1, n2;
    int ch;
    long int key;
    Records a(4);
    a.accept();
    a.display();
    a.heapSort();
    a.display();
    a.quicksort(0,a.n-1);
    cout<<" After QUICK SORT -> "<<endl;
    cout<<endl;
    a.display();
    cout << "Enter 1 for linear search, 2 for binary search : ";
    cin >> ch;
    cout<<endl;
    switch (ch)
    {
    case 1:
        cout << "Enter phone number to be searched : ";
        cin >> key;
        cout << endl;
        a.linearSearch(key);
        break;
    case 2:
        cout << "Enter phone number to be searched : ";
        cin >> key;
        cout << endl;
        a.binarySearch_nr(key);
        break;
    default:
        cout << "Invalid choice!";
        break;
    }
}