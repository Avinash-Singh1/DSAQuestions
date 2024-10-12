class Solution {
public:
    int f(int ind, int buy,vector<int> &values,int n,vector<vector<int>> &dp){
        if (ind == n) {
            return 0;
        }

        if (dp[ind][buy] != -1) return dp[ind][buy];

        int profit = 0;
        if (buy) {  // You can buy
            profit = max(-values[ind] + f(ind + 1, 0, values, n, dp),  // Buy
                        0 + f(ind + 1, 1, values, n, dp));  // Skip buying
        } else {  // You can sell
            profit = max(values[ind] + f(ind + 1, 1, values, n, dp),  // Sell
                        0 + f(ind + 1, 0, values, n, dp));  // Skip selling
        }

        return dp[ind][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        // vector<vector<int>> dp(n, vector<int>(2, -1));
        // return f(0,1,prices,n,dp);
        // tabulation start 
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        dp[n][0]=dp[n][1]=0;
      
        int profit;

        // Loop through the array in reverse order
        // for (int ind = n - 1; ind >= 0; ind--) {
        //     for (int buy = 0; buy <= 1; buy++) {
        //         if (buy == 0) { // We can buy the stock
        //             profit = max(0 + dp[ind + 1][0], -prices[ind] + dp[ind + 1][1]);
        //         }
        //         if (buy == 1) { // We can sell the stock
        //             profit = max(0 + dp[ind + 1][1], prices[ind] + dp[ind + 1][0]);
        //         }
        //         dp[ind][buy] = profit;
        //     }
        // }
        //  return dp[0][0];

    // tabulation ends here 

    // space optimi start
    int aheadnotbuy, aheadbuy,curbuy,curnotbuy;
    aheadnotbuy, aheadbuy=0;
      for (int ind = n - 1; ind >= 0; ind--) {
            curnotbuy = max( prices[ind] + aheadbuy ,0 + aheadnotbuy);
            curbuy = max( -prices[ind] + aheadnotbuy ,0 + aheadbuy);

            aheadbuy =curbuy;
            aheadnotbuy= curnotbuy;
        }

         return aheadbuy;
     // space optimi end
    }
};