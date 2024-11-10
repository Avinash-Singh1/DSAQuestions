class Solution {
public:
    int helper(int ind,int tar,vector<int>& coins, vector<vector<int>>& dp){
            // if(tar==0)return 1;
            if(ind==0) return (tar%coins[0]==0);
            if(dp[ind][tar]!=-1) return dp[ind][tar];
            int notT=  helper(ind-1,tar,coins,dp);
            int t= 0;
            if(coins[ind]<=tar) t=helper(ind,tar-coins[ind],coins,dp);
            return dp[ind][tar]=notT+t;
    }
    long change(int amount, vector<int>& coins) {
        int n=coins.size();
        int k=amount;
        vector<vector<long>> dp(n, vector<long>(k+1, 0));
        // return helper(n-1,amount,coins,dp);

        // tabulation 
        for(int tar=0;tar<=k;tar++){
            if(tar%coins[0]==0){
                dp[0][tar]=1;
            }
        }

        // main
        for(int ind=1;ind<n;ind++){
            for(int tar=0;tar<=k;tar++){
                long notT=  dp[ind-1][tar];
                long t= 0;
                if(coins[ind]<=tar) t=dp[ind][tar-coins[ind]];
                dp[ind][tar]=notT+t;
            }
        }
        return dp[n-1][k];
    }
};