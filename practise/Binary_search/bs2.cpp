#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> arr, int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] >= x) {
            // lower bound found:
            return i;
        }
    }
    return n;
}
int optimised(vector<int> arr,int l,int h,int tar,int &ans){
    if(l>h)return -1;
    
    int mid=(l+h)/2;
    if(arr[mid]>=tar){
       ans=mid;
        optimised(arr,l,mid-1,tar,ans);

    }else{
       
        optimised(arr,mid+1,h,tar,ans);

    }
    return ans;

}

int main()
{
    vector<int> arr = {3, 5, 8, 15, 19};
    int n = 5, x = 9;
    int ans= 0;
    int ind = lowerBound(arr, n, x);
    cout << "The lower bound is the index: " << ind << "\n";
    cout << "The lower bound is the index: " << optimised(arr,0,n-1,x,ans) << "\n";
    return 0;
}
