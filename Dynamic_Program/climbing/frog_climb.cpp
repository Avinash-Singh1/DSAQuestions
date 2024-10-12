#include <bits/stdc++.h>

using namespace std;

int solve(int ind, vector<int>& height, vector<int>& dp){
    if(ind==0) return 0;
    if(dp[ind]!=-1) return dp[ind];
    int left = solve(ind-1,height,dp)+ abs(height[ind]-height[ind-1]);
    int right = INT_MAX;
    if(ind>1){
        right = solve(ind-2,height,dp) + abs(height[ind]-height[ind-2]);
    }
    return dp[ind]= min(left,right);
}


int main() {

  vector<int> height{30,10,60 , 10 , 60 , 50};
  int n=height.size();
  vector<int> dp(n,-1);
  // cout<<solve(n-1,height,dp);
  
  // tabulation 
  dp[0]=0;
  for(int i =1; i<n;i++){
     int lft = dp[i-1]+abs(height[i]-height[i-1]);
     int rgt = INT_MAX;
     if(i>1) rgt = dp[i-2]+abs(height[i]-height[i-2]);
      dp[i]= min(lft,rgt);
  }
  cout<<dp[n-1]<<endl;
}
