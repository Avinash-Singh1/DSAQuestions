
#include <bits/stdc++.h>

using namespace std;

int solve(int ind, vector<int>& height, vector<int>& dp){
    if(ind==0) return 0;
    if(dp[ind]!= -1) return dp[ind];
    int one_step_jump= solve(ind-1,height,dp)+ abs(height[ind]-height[ind-1]);
    int two_step_jump=INT_MAX;
    if(ind>1)  two_step_jump= solve(ind-2,height,dp)+ abs(height[ind]-height[ind-2]);
    
    return dp[ind]=min(one_step_jump,two_step_jump);
}


int main() {

  vector<int> height{30,10,60 , 10 , 60 , 50};
  int n=height.size();
  vector<int> dp(n,-1);
//   cout<<solve(n-1,height,dp);
   int prev =0;  // dp[0]=0;
   int prev2 =0;
  for(int ind=1;ind<n;ind++){
     int one_step_jump= prev+ abs(height[ind]-height[ind-1]);
    int two_step_jump=INT_MAX;
    if(ind>1)  two_step_jump= prev2+ abs(height[ind]-height[ind-2]);
    int curr=min(one_step_jump,two_step_jump);
    prev2=prev;
    prev=curr;
  }

  cout<<"Final: "<<prev<<endl;


}