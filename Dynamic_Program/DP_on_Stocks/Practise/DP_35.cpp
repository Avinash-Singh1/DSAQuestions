#include <bits/stdc++.h> 

int maximumProfit(vector<int> &prices){
    // Write your code here.
    int n = prices.size();
    int ans=0;
    
    int mini=prices[0];
    for(int i =1;i<n;i++){
        int profit = prices[i]-mini;
        mini=min(mini,prices[i]);
        ans = max(ans,profit);
    }

    return ans;

}