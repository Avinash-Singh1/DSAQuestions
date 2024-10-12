
#include <bits/stdc++.h>
using namespace std;

int main(){
   
 vector<int> arr={2,6,5,8,11};
 int n=arr.size();
 int target=13;
 for (int i = 0; i < n; i++)
 {
    for (int j = i+1; j < n; j++)
    {
        if(arr[i]+arr[j]== target)
        {
            // return i,j;
            cout<<"i,j "<<i<<" "<<j<<endl;
        }
    }
    
 }
 
   
 return 0;  
}