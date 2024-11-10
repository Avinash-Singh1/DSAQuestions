class Solution {
public:
    
    string shortestCommonSupersequence(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0)); // Create a DP table

        // Initialize the base cases
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }
        for (int i = 0; i <= m; i++) {
            dp[0][i] = 0;
        }

            // Fill in the DP table to calculate the length of LCS
            for (int ind1 = 1; ind1 <= n; ind1++) {
                for (int ind2 = 1; ind2 <= m; ind2++) {
                    if (s1[ind1 - 1] == s2[ind2 - 1])
                        dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1]; // Characters match, increment LCS length
                    else
                        dp[ind1][ind2] = max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]); // Characters don't match, consider the maximum from left or above
                }
            }

         

            int i =n;int j =m;
            int len=dp[n][m];
            int index= len-1;
            string result="";
            while(i>0 && j>0){
                if(s1[i-1]==s2[j-1]){
                    result+=s1[i-1]; i--; j--;
                }else if(dp[i-1][j]>dp[i][j-1]){
                    result+= s1[i-1];
                    i--;
                }
                else{
                    result+= s2[j-1];
                    j--;
                }
            }
            while(i>0) {result+=s1[i-1];i--;}
            while(j>0){ result+=s2[j-1];j--;}
            reverse(result.begin(),result.end());
            return result;
    }
};