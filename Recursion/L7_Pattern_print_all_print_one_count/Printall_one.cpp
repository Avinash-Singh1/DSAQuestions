
#include <bits/stdc++.h>
using namespace std;
 bool PrintS(int ind,vector<int>ds,int s,int sum,int arr[],int n){
    if(ind==n){
        // condition satified
        if(s==sum){
            // for(auto it: ds) cout<<it<<" ";
            return true;
        }
        // cond not satisfied
        else return 0;
    }

    ds.push_back(arr[ind]);
    s+= arr[ind];

   if(PrintS(ind+1,ds,s,sum,arr,n)== true){
    return true;
   }
   s-= arr[ind];
   ds.pop_back();

   // not pick
    if(PrintS(ind+1,ds,s,sum,arr,n)== true){
    return true;
   }
   return false;

 }
int main(){
   
 int arr[]={1,2,1}  ;
 int n =3;
 int sum=2;
 vector<int>ds;
 PrintS(0,ds,0,sum,arr,n);

   
 return 0;  
}