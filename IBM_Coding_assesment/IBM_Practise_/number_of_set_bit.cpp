
#include <bits/stdc++.h>
using namespace std;

int main(){
  map<int,int> mpp;  
 int n =11;

 while (n>0)
 {
    int bit =n%2;
    n=n/2;
    mpp[bit]++;
 }

 for(auto i: mpp){
    cout<<i.first<<" "<<i.second<<endl;
 }
 
 
   
 return 0;  
}