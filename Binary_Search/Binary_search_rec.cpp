
#include <bits/stdc++.h>
using namespace std;
 int FindTar(vector<int> arr,int l, int h,int tar){
    if(l>h) return -1;

    int mid=l+(h-l)/2;
    if(arr[mid]==tar){
        return mid;
    }
    else if(arr[mid]>tar){
       return FindTar(arr,l,mid-1,tar);
    }else{
       return FindTar(arr,mid+1,h,tar);
    }
    
   
 }
int main(){
   
 vector<int>arr={3,5,6,7,8,9,12,34};
 int n=arr.size();
 int result =FindTar(arr,0,n-1,9);
 cout<<"result: "<<result<<endl;
   
 return 0;  
}