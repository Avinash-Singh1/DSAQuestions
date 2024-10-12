
#include <bits/stdc++.h>
using namespace std;

int main(){
   
   int j =0;
 vector<int> arr = {3,0,5,0,6};
 for (int  i = 0; i < arr.size(); i++)
 {
    if(arr[i] == 0)
    {
        j=i;
        break;
    }
 }

 for (int  i = j+1; i < arr.size(); i++)
 {
    if(arr[i]!= 0)
    {
        swap(arr[i],arr[j]);
        j++;
    }
 }

 for(auto i: arr)
 {
    cout<<i<<endl;
 }
 
   
   
 return 0;  
}