
#include <bits/stdc++.h>
using namespace std;

int search(vector<int> &arr, int n, int k)
{
    int l = 0;
    int h = n - 1;
    int ans =-1;
    while (l <= h)
    {
        int mid = l + (h - l) / 2;
        if(arr[mid]==k)
        {   ans =mid;
           
            l=mid+1;
            
        }
        // left soreted ?
        else if (arr[l] <= arr[mid])
        {
            if (arr[l] <= k && k <= arr[mid])
            {
                h = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        // right sorted ?
        else
        {
            if (arr[mid] <= k && k <= arr[h])
            {
                l = mid + 1;
            }
            else
            {
                h = mid - 1;
            }
        }
    }
    return ans;
}

    int main()
    {
        vector<int> arr = {7, 8, 9, 1, 2,3, 3, 4, 5, 6};
        int n = 10, k = 3;
        int ans = search(arr, n, k);
        if (ans == -1)
            cout << "Target is not present.\n";
        else
            cout << "The index is: " << ans << "\n";
        return 0;
    }
