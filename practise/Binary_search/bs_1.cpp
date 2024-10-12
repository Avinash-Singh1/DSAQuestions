
#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>& nums, int target) {
   int n =nums.size();
   int l = 0; int high = n-1;

   while(l<=high){
    int mid= l+(high-l)/2;
        if(nums[mid]==target){
            return mid;
        }
        else if(nums[mid]>target){
            high=mid-1;
        }
        else{
            l=mid+1;
        }
   }
   return -1;
}

int binarySearchrec(vector<int>& nums, int l ,int h,int k) {
     if(l>h)return -1;
   
   
    int mid= l+(h-l)/2;
        if(nums[mid]==k){
            return mid;
        }
        else if(nums[mid]>k){
           return  binarySearchrec(nums,l,mid-1,k);
        }
        else{
            return binarySearchrec(nums,mid+1,h,k);
        }
   
//    return -1;
}

int main()
{
    vector<int> a = {3, 4, 6, 7, 9, 12, 16, 17};
    int target = 6;
    int ind = binarySearch(a, target);
    if (ind == -1) cout << "The target is not present." << endl;
    else cout << "The target is at index: "
                  << ind << endl;
    int n = a.size();
    cout<<endl;
    cout<<binarySearchrec(a,0,n-1,16);            
    return 0;
}