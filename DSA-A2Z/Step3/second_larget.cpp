
#include <bits/stdc++.h>
using namespace std;
void mergeall(vector<int> &arr, int l, int m, int r)
{
    int i = l;
    int j = m + 1;
    int k = l;
    int temp[r-l];
    while (i <= m && j <= r)
    {
        if (arr[i] <= arr[j])
        {
            temp[k-l] = arr[i];
            i++;
            k++;
        }
        else
        {
            temp[k-l] = arr[j];
            j++;
            k++;
        }
    }
    while (i <= m)
    {
        temp[k-l] = arr[i];
        i++;
        k++;
    }

    while (j <= r)
    {
        temp[k-l] = arr[j];
        j++;
    }

    for (int i = l; i <= r; i++)
    {
        arr[i] = temp[i-l];
        // cout<<"  "<<temp[i]<<" ";
    }
    // cout<<endl;
}
void mergesort(vector<int> &arr, int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        mergesort(arr, l, m);
        mergesort(arr, m + 1, r);
        mergeall(arr, l, m, r);
    }
}
int main()
{

    vector<int> arr = {4, 77, 4, 8, 77};
    int n = arr.size();
    cout << "Before sorting" << endl;
    for (auto i : arr)
    {
        cout << " " << i << "";
    }
    mergesort(arr, 0, n - 1);
    cout << endl;
    cout << " after sorting" << endl;
    for (auto i : arr)
    {
        cout << " " << i << "";
    }

int secondl=0;
  for (int i = n-1; i > 0; i--)
  {
    if(arr[i] != arr[i-1])
    {   secondl=i-1;
        break;
    }
  }
  cout<<"\nSecond Larget: "<<arr[secondl];
  


    return 0;
}