
#include <bits/stdc++.h>
using namespace std;

int main(){
   
 vector<int> arr ={1,1,2,2,3,3,4} ;
 int n =arr.size();
 int maxi =0;
 for(auto i: arr)
 {
    maxi=max(maxi,i);
 }
 cout<<maxi<<" ma";

 vector<int>hass(maxi+1,0);
 cout<<"\nhas: "<<hass.size()<<endl;

 for(int i= 0; i<n;i++) 
 {
    hass[arr[i]]++;
 }

 for(int i =0; i < n;i++)
 { 
   if(hass[i]==1)
   {
    cout<<i<<" ";
    break;
   }
 }
   
 return 0;  
}