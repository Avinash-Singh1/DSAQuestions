
#include <bits/stdc++.h>
using namespace std;
 bool PrintS(int ind,vector<int>ds,int s,int sum,int arr[],int n, vector<vector<int>> &result){
    if(ind==n){
        // condition satified
        if(s==sum){
            // for(auto it: ds) cout<<it<<" ";
            result.push_back(ds);
            return true;
        }
        // cond not satisfied
        else return 0;
    }

    ds.push_back(arr[ind]);
    s+= arr[ind];

   if(PrintS(ind+1,ds,s,sum,arr,n,result)== true){
    return true;
   }
   s-= arr[ind];
   ds.pop_back();

   // not pick
    if(PrintS(ind+1,ds,s,sum,arr,n,result)== true){
    return true;
   }
   return false;

 }
int main(){
   
 int arr[]={1,2,1}  ;
 int n =3;
 int sum=2;
 vector<int>ds;
 vector<vector<int>>result;
 PrintS(0,ds,0,sum,arr,n,result);

    for(auto it: result){
        for(auto i: it){
            cout<<i<<" ";
        }
        cout<<endl;
    }
   
 return 0;  
}