
#include <bits/stdc++.h>
using namespace std;

// Function to solve the problem using dynamic programming
int solveUtil(int ind, vector<int>& arr, vector<int>& dp) {
   if(ind== 0) return arr[ind];
   if(ind<0) return 0;
   if(dp[ind] !=  -1) return dp[ind];
   int pick = arr[ind] + solveUtil(ind-2,arr,dp);
   int notpick= 0 + solveUtil(ind-1,arr,dp);

   return dp[ind]=max(pick,notpick);

}

// Function to initiate the solving process
int solve(int n, vector<int>& arr) {
    vector<int> dp(n, -1); // Initialize the DP table with -1
    return solveUtil(n - 1, arr, dp); // Start solving from the last element
}

int main() {
    vector<int> arr{2, 1, 4, 9,3,5,7};
    int n = arr.size();
    
    // Call the solve function and print the result
    cout << solve(n, arr);

    return 0;
}
