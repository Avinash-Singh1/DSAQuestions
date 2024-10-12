#include <bits/stdc++.h> 

// Function to solve the 0/1 Knapsack problem using memoization
int knapsackUtil(vector<int>& wt, vector<int>& val, int ind, int W, vector<vector<int>>& dp) {
      // Base case: If no items are left or knapsack has no capacity
    if (ind == 0) {
        if (wt[0] <= W) return val[0]; // If the first item fits, return its value
        else return 0; // Otherwise return 0
    }
    
    // If the result for this state is already calculated, return it
    if (dp[ind][W] != -1) {
        return dp[ind][W];
    }

    // Calculate the maximum value by either excluding or including the current item
    int notTaken = knapsackUtil(wt, val, ind - 1, W, dp); // Not including the item
    int taken = 0;
    
    // Check if the current item can be included without exceeding capacity
    if (wt[ind] <= W) {
        taken = val[ind] + knapsackUtil(wt, val, ind - 1, W - wt[ind], dp); // Include the item
    }

    // Store and return the result
    return dp[ind][W] = max(notTaken, taken);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
    // memoization starts
	vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
    return knapsackUtil(weight, value, n - 1, maxWeight, dp);
    // memoization starts

    // tabulation starts
    
}