#include <iostream>
using namespace std;

int x[20], n;

bool place(int k, int i) {
    for (int j = 1; j < k; j++) {
        if (x[j] == i || abs(x[j] - i) == abs(j - k)) {
            return false;
        }
    }
    return true;
}

void printSolution(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (x[i] == j) {
                cout << "Q ";
            } else {
                cout << ". ";
            }
        }
        cout << endl;
    }
    cout << endl;  
}

void nqueen(int k, int n) {
    for (int i = 1; i <= n; i++) {
        if (place(k, i)) {
            x[k] = i;
            if (k == n) {
                printSolution(n);
            } else {
                nqueen(k + 1, n);
            }
        }
    }
}

int main() {
    cout << "Enter the number of queens: ";
    cin >> n;
    
    cout << "Solutions:\n";
    nqueen(1, n);
    
    return 0;
}
