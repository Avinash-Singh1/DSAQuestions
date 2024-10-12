
#include <bits/stdc++.h>
using namespace std;
set<int>FindUnion(vector<int> arr1,vector <int> arr2, int n, int m){
   set<int>unionarr;
   for(auto i :arr1)
   {
    unionarr.insert(i);
   }
    for(auto j :arr2)
   {
    unionarr.insert(j);
   }

   return unionarr;
   
}
int main(){
   
  
  int n = 10, m = 7;
  vector<int> arr1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  vector<int> arr2 = {2, 3, 4, 4, 5, 11, 12};
  set < int > Union = FindUnion(arr1, arr2, n, m);
 
   for(auto i: Union)
   {
    cout<<" i: "<<i<<" ";
   }
 return 0;  
}