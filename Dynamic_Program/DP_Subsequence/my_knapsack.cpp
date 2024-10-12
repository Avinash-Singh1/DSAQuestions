#include <bits/stdc++.h> 

// Function to solve the 0/1 Knapsack problem using memoization
int knapsackUtil(vector<int>& wt, vector<int>& val, int ind, int W, vector<vector<int>>& dp) {
    //base case 
    if(ind==0){
        if(wt[ind]<=W) return val[ind];
        return 0;
    }
    
    if(dp[ind][W]!=-1)return dp[ind][W];
    
    //main
    int nt = 0+knapsackUtil(wt,val,ind-1,W,dp);
    int t= INT_MIN;
    if(wt[ind]<=W) t= val[ind]+ knapsackUtil(wt,val,ind-1,W-wt[ind],dp);

    return dp[ind][W]=max(nt,t);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// vector<vector<int>> dp(n,vector<int>(maxWeight+1,-1));
    // return knapsackUtil(weight,value,n-1,maxWeight,dp);

    //tabulation 
    vector<vector<int>> dp(n,vector<int>(maxWeight+1,0));

    //base case
    for(int W=1;W<=maxWeight;W++){
        if(weight[0]<=W){
            dp[0][W]=value[0];
        }
        else{
            dp[0][W]=0;
        }
    }
    
    for(int ind =1;ind<n;ind++){
        for (int W = 0; W <= maxWeight; W++) {
            int nt = 0+dp[ind-1][W];
            int t= INT_MIN;
            if(weight[ind]<=W) t= value[ind]+ dp[ind-1][W-weight[ind]];
            dp[ind][W]=max(nt,t);
        }
    }

    return dp[n-1][maxWeight];


}