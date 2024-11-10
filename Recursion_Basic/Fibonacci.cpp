
#include <bits/stdc++.h>
using namespace std;

// int fib(int n,vector<int>& dp){
//     if(n<=1)return n;
//     if(dp[n]!=-1)return dp[n];
//     return dp[n]=fib(n-1,dp)+fib(n-2,dp);
// }

int fib2(int n,vector<int>& dp){
    // if(n<=1)return n;
    int prev2=0;
    int prev =1;
    for (int i = 2; i <= n; i++)
    {
        int cur = prev +prev2;
        prev =cur;
        prev2 = prev;
    }
    return prev;
    // if(dp[n]!=-1)return dp[n];
    // return dp[n]=fib(n-1,dp)+fib(n-2,dp);
}
int main(){
   
 int n =5;
 vector<int> dp(n+1,-1);
 int result=fib2(n,dp); 
 cout<<"Result: "<<result<<endl; 
 return 0;  
}