
#include <bits/stdc++.h>
using namespace std;

bool searchInARotatedSortedArrayII(vector<int>&arr, int k) {
    int n = arr.size(); // size of the array.
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;

        //if mid points the target
        if (arr[mid] == k) return true;

        //Edge case:
        if (arr[low] == arr[mid] && arr[mid] == arr[high]) {
            low = low + 1;
            high = high - 1;
            continue;
        }

        //if left part is sorted:
        if (arr[low] <= arr[mid]) {
            if (arr[low] <= k && k <= arr[mid]) {
                //element exists:
                high = mid - 1;
            }
            else {
                //element does not exist:
                low = mid + 1;
            }
        }
        else { //if right part is sorted:
            if (arr[mid] <= k && k <= arr[high]) {
                //element exists:
                low = mid + 1;
            }
            else {
                //element does not exist:
                high = mid - 1;
            }
        }
    }
    return false;
}
bool searchInARotatedSortedArrayII2(vector<int> arr, int k)
{ 
    int n =arr.size();
    int l=0; int h= n-1;

    while(l<=h){
        int mid =l+(h-l)/2;
        if(arr[mid]==k) return true;
        if(arr[l]==arr[mid] && arr[mid]==arr[h]){
            l++; h--;
            continue;
        }
        else if(arr[l]<= arr[mid] ){
            if(arr[l]<=k && k<=arr[mid]) h=mid-1;
            else l=mid+1;
        }
        else{
           if(arr[mid]<k && k<arr[h]) {
            l= mid+1;
           }
           else{
            h= mid-1;
           }
        }
    }
    return false;
}

int main()
{
    vector<int> arr = {7, 8, 1, 2, 3, 3, 3, 4, 5, 6};
    int k = 8;
    bool ans = searchInARotatedSortedArrayII2(arr, k);
    if (!ans)
    cout << "Target is not present.\n";
    else
    cout << "Target is present in the array.\n";
    return 0;
}

