#include <bits/stdc++.h>

using namespace std;
int f(int ind, vector<int> &dp){
    if(ind==0) return 1;
    if(ind==1) return 1;
    if(dp[ind]!=-1){
        return dp[ind];
    }
    int l = f(ind-1,dp);
    int r = f(ind-2,dp);
    return dp[ind]= l+r;
}

int main() {

   int n=5;
//   vector<int> dp(n+1,-1);
//   cout<<"Result: "<<f(n,dp)<<endl;

  vector<int> dp(n+1,-1);
  dp[0]= 1;
  dp[1]= 1;
  
  for(int i=2; i<=n; i++){
      dp[i] = dp[i-1]+ dp[i-2];
  }
  cout<<dp[n];
  return 0;
}