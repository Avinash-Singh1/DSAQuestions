
#include <bits/stdc++.h>
using namespace std;
 int FindTar(vector<int> arr,int l, int h,int tar,int ans){
    if(l>h) return ans;

    int mid=l+(h-l)/2;
    
    if(arr[mid]>=tar){
       ans=mid;
       return FindTar(arr,l,mid-1,tar,ans);
    }else{
       return FindTar(arr,mid+1,h,tar,ans);
    }   
 }
int main(){
   
 vector<int>arr={3,5,6,7,8,12,34};
 int n=arr.size();
 int result =FindTar(arr,0,n-1,9,n-1);
 cout<<"result: "<<result<<endl;
   
 return 0;  
}