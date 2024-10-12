
#include <bits/stdc++.h>
using namespace std;

int searchInARotatedSortedArrayII(vector<int> &arr, int k)
{
    int h = arr.size()-1;
    int l = 0;
    int ans = -1;
    while (l <= h)
    {
        int mid = l+( h-l) / 2;
        if (arr[mid] == k)
        {
            ans = mid;
            h= mid-1;
        }
        else if (arr[l] == arr[mid] && arr[mid] == arr[h])
        {
            l++;
            h--;
            continue;
            
        }
        // left sorted
        else if (arr[l] <= arr[mid])
        {
            if (arr[l] <= k && k < arr[mid])
            {
                h = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        // right sorted
        else
        {
            if (arr[mid] < k && k <= arr[h])
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
    vector<int> arr = {7, 8, 1, 2, 3, 3, 4, 4, 5, 6};
    int k = 4;
    int ans = searchInARotatedSortedArrayII(arr, k);
    if (ans==-1)
        cout << "Target is not present.\n";
    else
        cout << "Target is present in the array: " << ans << endl;
    return 0;
}
