
#include <bits/stdc++.h>
using namespace std;

void BubbleSort(int arr[], int n)
{
    // int flag =0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < (n-i-1); j++)
        {
             if (arr[j] > arr[j+ 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        
       
    }

     cout << "Array Before Sorting" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << " " << arr[i] << endl;
    }

}
int main()
{

    cout << "enter array size" << endl;
    int n;
    cin >> n;
    cout << "Enter " << n << "numbers" << endl;
    int arr[n];
    for (size_t i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    BubbleSort(arr, n);

    return 0;
}