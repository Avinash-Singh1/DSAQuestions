


#include <bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int> &arr) {
   int n = arr.size();

   for(int i=0;i<n;i++)
   {
        if((i==0 || arr[i]>arr[i-1]) &&(arr[i]>arr[i+1] || i==n-1)){
            return i;
        }
        else{
            if((arr[i]>arr[i+1]) && (arr[i]>arr[i-1])){
                return i;
            }
        }
   }
}

int findPeakElement_optimised(vector<int> &arr) {
   int n = arr.size();
   if(n==1) return arr[0];
   if(arr[0]>arr[1]) return arr[0];
   if(arr[n-1]>arr[n-2]) return arr[n-1];
   int l = 1; int h =n-2;
    while(l<=h){
            int mid = l + (h-l)/2;
            if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]) return mid;
            else if(arr[mid]>arr[mid-1]){
                l= mid+1;
            }
            else{
                h = mid-1;
            }
    }
    return -1;
}

int main()
{
    vector<int> arr = {1, 2, 3,2,1, 4,2};
    int ans = findPeakElement(arr);
    cout << "The peak is at index: " << ans << "\n";
    return 0;
}

