class Solution {
  public:
   vector<string> all_longest_common_subsequences(string s, string t) {
    int n = s.size();
    int m = t.size();
    
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    
    // Tabulation
    for (int i = 1; i <= n; i++) dp[i][0] = 0;
    for (int j = 1; j <= m; j++) dp[0][j] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i - 1] == t[j - 1]) 
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

   
    
         int len = dp[n][m];
         int i =n; int j=m;
         int index= len-1;
         vector<char> result;
        
        
         while(i>0 && j>0)
         {
            if(s[i-1]==t[j-1]){
                result.push_back(s[i-1]);
                index--;
                i--; j--;
            }else if (s[i-1]>t[j-1]){
                i--;
            }else{
                j--;
            }
         }
         
        vector<string> ans;
        reverse(result.begin(), result.end());  
        string lcs(result.begin(), result.end());  // Convert `res` to a single string
        ans.push_back(lcs);  
        return ans;
         
      
}

};