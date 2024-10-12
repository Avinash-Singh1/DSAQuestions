
#include <bits/stdc++.h>
using namespace std;

int main(){
   
 int n =4;
 int prev=1; int prev2=0;

 for(int i =2;i<=n;i++){
    int cur= prev+prev2;
    prev2=prev;
    prev=cur;
 }  
 cout<<prev<<endl;
   
 return 0;  
}