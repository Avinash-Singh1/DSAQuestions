
#include <bits/stdc++.h>
using namespace std;
 bool isPrime(int n){
    if(n<=1) false;
    if(n<=3 ) true;
    if(n%2==0 || n%3 ==0)
    {
        return false;
    }
    else{
         for(int i =5 ; i*i<=n;i=i+6){
            if(n%i==0 && n%(i+2)==0) return false;
         }
       

    }
     return true;


 }
int main(){
   
 int n =157;
 bool result =isPrime(n); 
 cout<<(result?"Prime":"Not Prime")<<endl; 
   
 return 0;  
}