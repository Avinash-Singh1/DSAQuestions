
#include <bits/stdc++.h>
using namespace std;

int floor(vector<int> arr, int l, int h, int tar)
{
    int last = 0;
    while (l <= h)
    {
        int mid = l + (h - l) / 2;

        if (arr[mid] <= tar)
        {
            last = arr[mid];
            l=mid+1;
        }
        else
        {
            h = mid -1;
        }
    }
    return last;
}
int ceilval(vector<int> arr, int l, int h, int tar)
{
    int ceil = 0;
    while (l <= h)
    {
        int mid = l + (h - l) / 2;

        if (arr[mid] >= tar)
        {
            ceil = arr[mid];
            h = mid -1;
        }
       
        else
        {
            l = mid + 1;
        }
    }
    return ceil;
}


int main()
{

    vector<int> arr = {5, 7, 7, 8, 8, 10};
    int n = arr.size();
    int result[]= {floor(arr,0,n-1,9),ceilval(arr,0,n-1,9)};
    for(auto i:result)
    {
        cout<<i<<endl;
    }
    // cout << "result: " << result << endl;
    

    return 0;
}