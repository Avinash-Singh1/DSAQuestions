class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini =INT_MAX;
        int n =prices.size();
        int profit =0;
        for(int i =1;i<n;i++){
            mini =min(mini,prices[i-1]);
            profit=max(profit,prices[i]-mini);
        }
        return profit;
    }
};