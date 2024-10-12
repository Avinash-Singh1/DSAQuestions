class Solution {
public:
    int f(int ind, int buy,int cap,vector<int>& prices, int n , vector<vector<vector<int>>> &dp){
        if(cap==0) return 0;
        if(ind==n) return 0;
        int profit =0;
        if(dp[ind][buy][cap]!=-1)return dp[ind][buy][cap];
        if(buy){
            profit = max(-prices[ind]+f(ind+1,0,cap,prices,n,dp),
                       0+f(ind+1,1,cap,prices,n,dp));
        }
        else{
             profit = max(prices[ind]+f(ind+1,1,cap-1,prices,n,dp),
                     0+f(ind+1,0,cap,prices,n,dp));
        }
        return dp[ind][buy][cap]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n =prices.size();
        if(n==0) return 0;
        // ind buy cap-limit
        // vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        // return f(0,1,2,prices,n,dp);

        // tabulation starts here 
         vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));

        // there is no need to write base case as intial dp value =0
        // for(int ind =0;ind<n;ind++){
        //     for(int buy =0;buy<2;buy++){
        //         dp[ind][buy][0]=0;
        //     }
        // }

         
          for(int buy = 0; buy < 2; buy++){
                for(int cap = 0; cap <= 2; cap++){
                    dp[n][buy][cap] = 0; // No transactions possible on or after the last day
                }
          }

        // changing parameter
          for(int ind = n-1; ind >= 0; ind--){
                for(int buy = 0; buy < 2; buy++){
                    for(int cap = 1; cap <= 2; cap++){ // cap must be at least 1 (cap = 0 means no transactions left)
                        if(buy){
                            // Option to buy or skip
                            dp[ind][buy][cap] = max(-prices[ind] + dp[ind+1][0][cap],  // Buy and move to sell state
                                                    dp[ind+1][1][cap]);               // Skip buying
                        } else {
                            // Option to sell or skip
                            dp[ind][buy][cap] = max(prices[ind] + dp[ind+1][1][cap-1], // Sell and use one transaction
                                                    dp[ind+1][0][cap]);               // Skip selling
                        }
                    }
                }
        }

        return dp[0][0][2];
        


    }
};