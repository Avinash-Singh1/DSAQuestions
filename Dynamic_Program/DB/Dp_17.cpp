class Solution{
	public:
  const int MOD = 1e9 + 7;  // Modulus as required by the problem
    
    int helper(int ind, int tar, int arr[], vector<vector<int>> &dp) {
        if (tar == 0) return 1;  // Base case: found a valid subset
        if (ind == 0) return (arr[0] == tar || tar == 0) ? 1 : 0;  // Base case: single element check

        if (dp[ind][tar] != -1) return dp[ind][tar];  // Memoization
        
        int nt = helper(ind - 1, tar, arr, dp) % MOD;  // Not taking current element
        
        int t = 0;
        if (arr[ind] <= tar)  // Take the current element if it can be included in the sum
            t = helper(ind - 1, tar - arr[ind], arr, dp) % MOD;
        
        return dp[ind][tar] = (t + nt) % MOD;  // Store the result mod MOD
    }
    
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        // vector<vector<int>> dp(n, vector<int>(sum + 1, -1));  // Memoization table
        // return helper(n - 1, sum, arr, dp)% MOD;
        //tabulation
        vector<vector<int>> dp(n+1, vector<int>(sum + 1, 0));
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=sum;j++){
                  // Not including the current element
                dp[i][j] = dp[i - 1][j] % MOD;

                // Including the current element if it's <= current sum
                if (arr[i - 1] <= j) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - arr[i - 1]]) % MOD;
                }
            }
        }
        
        return dp[n][sum];
	}
	  
};