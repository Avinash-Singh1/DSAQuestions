
#include <bits/stdc++.h>
using namespace std;

int main(){
   
   int m=75;
   int n=15;
   int ans;
    // cin>>m>>n;
    while(m!=n)
    {
        if(m>n)
        {
            m=m-n;
        }
        else
        {
            n=n-m;
        }
    }
   cout<<m;
   
 return 0;  
}