class Solution {
  public:
    int f(int n, int k,vector<int>& arr,vector<int>&dp)
    {
        // if(ind==0) return 0;
        // if(dp[ind]!=-1) return dp[ind];
        // int minenergy=INT_MAX;
        // for(int j= 1;j<=k;j++){
        //   if(ind-j>=0){
        //     int jump =f(ind-j,k,arr,dp)+abs(arr[ind]-arr[ind-j]);
        //     minenergy=min(minenergy,jump);
        //   }
           
        // }
        // return dp[ind]= minenergy;
        
        dp[0]=0;
        for(int ind =1;ind<n;ind++){
            int min_energy= INT_MAX;
            for(int j =1;j<=k;j++){
                if(ind-j>=0){
                    int jump= dp[ind-j] + abs(arr[ind]-arr[ind-j]);
                    min_energy=min(min_energy,jump);
                }
                
            }
            dp[ind]=min_energy;
        }
        return dp[n-1];
    }
    int minimizeCost(int k, vector<int>& arr) {
        // Code here
        int n  =arr.size();
        vector<int> dp(n, -1);
        return f(n,k,arr,dp);
    }
};