#include <iostream>
#include <vector>
using namespace std;

// Custom reverse function
void reversefun(vector<int>& arr, int s, int e) {
    while (s < e) {
        int temp = arr[s];
        arr[s] = arr[e];
        arr[e] = temp;
        s++;
        e--;
    }
}

// Function to perform optimal left rotation
void OptimalLeftRotate(vector<int>& arr, int n, int d) {
    if (n == 0) {
        return;
    } else {
        d = d % n; // Normalize d

        reversefun(arr, 0, d - 1); // Reverse the first 'd' elements
        reversefun(arr, d, n - 1); // Reverse the remaining elements
        reversefun(arr, 0, n - 1); // Reverse the entire array
    }
}

int main() {
    int n = 7;
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    int d = 3;

    cout << "Before rotation:" << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    OptimalLeftRotate(arr, n, d);

    cout << "After rotation:" << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
