
#include <bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int>& arr) {
   int n =arr.size();
   if(n==0)return arr[0];
   
    
        for (int i = 0; i < n; i++)
        {
            if(i==0){
                if(arr[i]!= arr[i+1]) return arr[i];
            }
            if(i==n-1){
                if(arr[i]!= arr[i-1]) return arr[i];
            }
            else{
                if(arr[i]!= arr[i+1] && arr[i]!= arr[i-1]) return arr[i];
            }
        }

     return -1;   
   
}

int singleNonDuplicate_optimised(vector<int>& arr) {
   int n =arr.size();
   if(n==1)return arr[0];
   if(arr[0]!=arr[1])return arr[0]; 
   if(arr[n-1]!=arr[n-2])return arr[n-1]; 

   int l=1; int h= n-2;
   while(l<=h){
     int mid = l+(h-l)/2;
     if(arr[mid]!= arr[mid+1] && arr[mid]!= arr[mid-1]) return arr[mid];

     // left 
     if((mid %2 ==1 && arr[mid]==arr[mid-1]) && (mid %2 ==0 && arr[mid]==arr[mid-1])){
         // eliminate left 
        l = mid+1;
     }
     // right part
     else{  //  mid %2 ==0 && arr[mid]==arr[mid-1]) && (mid %2 ==1 && arr[mid]==arr[mid+1])
        // eliminate right part
        h = mid-1;
     }
   }
   
    return -1;
   
}

int main()
{
    vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 4,  5, 6, 6};
    // int ans = singleNonDuplicate(arr);   // brute 
    int ans = singleNonDuplicate_optimised(arr);
    cout << "The single element is: " << ans << "\n";
    return 0;
}
