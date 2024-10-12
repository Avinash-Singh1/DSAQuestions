#include <bits/stdc++.h>
using namespace std;

// Function to find the minimum cost to reach the end using at most 'k' jumps
int solveUtil(int ind, vector<int>& height, vector<int>& dp, int k) {
   if(ind==0) return 0;
   int mini= INT_MAX;
   if(dp[ind]!=-1)return dp[ind];
   for(int i =1;i<=k;i++){
        if(ind-i>=0){
            int e_jump = solveUtil(ind-i,height,dp,k)+abs(height[ind]-height[ind-i]);
            mini =min(mini,e_jump);
        }
   }
   return dp[ind]=mini;
}

// Function to find the minimum cost to reach the end of the array
int solve(int n, vector<int>& height, int k) {
    vector<int> dp(n, -1); // Initialize a memoization array to store calculated results
    // return solveUtil(n - 1, height, dp, k); 
    // Start the recursion from the last index

    dp[0]=0;
    
    for(int ind =1;ind<n;ind++){
        int mini =INT_MAX;
        for(int i =1;i<=k;i++){
            if(ind-i>=0){
                int e_jump = dp[ind-i]+abs(height[ind]-height[ind-i]);
                mini =min(mini,e_jump);
            }
        }
        dp[ind]=mini;
    }
    cout<<dp[n-1]<<endl;
}

int main() {
    vector<int> height{30, 10, 60, 10, 60, 50};
    int n = height.size();
    int k = 2;
    vector<int> dp(n, -1); // Initialize a memoization array for the main function
    solve(n, height, k) ; // Print the result of the solve function
    return 0;
}
