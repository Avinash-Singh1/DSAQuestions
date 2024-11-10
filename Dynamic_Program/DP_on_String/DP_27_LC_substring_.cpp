class Solution {
  public:
     
   
    int longestCommonSubstr(string s, string t) {
        // your code here
            int n = s.size();
            int m = t.size();
            
            vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
               int maxLen = 0; 
            // Tabulation
            for (int i = 1; i <= n; i++) dp[i][0] = 0;
            for (int j = 1; j <= m; j++) dp[0][j] = 0;
        
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    if (s[i - 1] == t[j - 1]) 
                        {
                            dp[i][j] = 1 + dp[i - 1][j - 1];
                            maxLen = max(maxLen,dp[i][j]);
                        }
                    else{
                        dp[i][j] =0;
                        
                    }
                }
            }
            return maxLen;
             
                    
         
    }
};