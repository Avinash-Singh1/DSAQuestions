
#include <bits/stdc++.h>
using namespace std;
 int PrintS(int ind,vector<int>ds,int s,int sum,int arr[],int n){
    if(ind==n){
        // condition satified
        if(s==sum){
            // for(auto it: ds) cout<<it<<" ";
            return 1;
        }
        // cond not satisfied
        else return 0;
    }

    ds.push_back(arr[ind]);
    s+= arr[ind];

   int l =PrintS(ind+1,ds,s,sum,arr,n);
   s-= arr[ind];
   ds.pop_back();

   // not pick
   int r= PrintS(ind+1,ds,s,sum,arr,n);
   return l+r;
   
   

 }
int main(){
   
 int arr[]={1,2,1}  ;
 int n =3; 
 int sum=2;
 vector<int>ds;
 cout<<PrintS(0,ds,0,sum,arr,n);

   
 return 0;  
}