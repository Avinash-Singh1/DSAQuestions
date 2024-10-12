
#include <bits/stdc++.h>
using namespace std;
int getMaximumEvenSum(vector<int>arr, int n ){
    int pos_sum =0;
    // calculate sum of positive elements
    for(int i = 0; i < n; i++){
        if(arr[i] > 0) {
            pos_sum += arr[i];
        }
    }

    // if the sum of positive eleemnts is even return it;
    if(pos_sum%2==0)
    {
        return pos_sum;
    }

    // find the maximum even sum by modifying odd positive elements
    int ans=INT_MIN;
    for(int i=0; i<n;i++){
        if(arr[i]%2!=0){
           
                if(arr[i]>0)
                {
                     ans=max(ans,pos_sum-arr[i]);
                }
              else{
                    ans= max(ans,pos_sum+arr[i]);
                }
        }
      
    }
    return ans;

}
int main(){
   
 vector<int> arr={-1,-2,-3,8,7};
 int n =5;  
 cout<<getMaximumEvenSum(arr,n);
 return 0;  
}