


#include <bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int> &arr) {
    int n = arr.size(); //Size of array.
    if(n==0) return 0;
    if (n==1) return arr[0];
    if(arr[0]>arr[1]) return arr[0];
    if(arr[n-1]>arr[n-2]) return arr[n-1];

    int l=1; int h =n-2;
    while(l<=h)
    {
        int mid = l+(h-l)/2;

        if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
        {
            return arr[mid];
        }
        else{
            if(arr[mid]>arr[mid+1])
            {
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
    }
    return -1;
    
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8,9, 5, 1};
    int ans = findPeakElement(arr);
    cout << "The peak is at index: " << ans << "\n";
    return 0;
}

