
#include <bits/stdc++.h>
using namespace std;

int main(){
   
 vector<int>arr ={4,2,7,8,1,9};  
 int n = arr.size();
 int l =0;
 int r =n-1;
 int target =15;
 int sum =0;

 sort(arr.begin(), arr.end());

    while(l<r)
    {
       sum = arr[l]+arr[r];
        if(sum==target){
            cout<<arr[l]<<" + "<<arr[r]<<"= "<<arr[l]+arr[r]<<" Yes"<<endl;
        }
        if(sum<target)
        {
            l++;
        }
        else{
            r--;
        }
    }

   
 return 0;  
}