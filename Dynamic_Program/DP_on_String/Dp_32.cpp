
const int MOD = 1e9 + 7;

int f(int i, int j,string &s1, string &s2,vector<vector<int>>&dp){
	if(j<0) return 1;
	if(i<0) return 0;

	if(dp[i][j]!=-1) return dp[i][j];
	// match
	if(s1[i]== s2[j]){
		return dp[i][j]=f(i-1,j-1,s1,s2,dp)+f(i-1,j,s1,s2,dp);
	}
	return dp[i][j]=f(i-1,j,s1,s2,dp);
}
int distinctSubsequences(string &str, string &sub)
{
	// Write your code here.
	
	int n = str.size();
	int m = sub.size();
	// vector<vector<int>> dp(n, vector<int>(m, -1));  
    // return f(n - 1, m - 1, str, sub, dp);

	// tabulation 
	vector<vector<int>> dp(n+1, vector<int>(m+1, 0)); 
	for(int i=0;i<=n;i++){
		dp[i][0]=1;
	} 
	// for(int j=1;j<=m;j++){
	// 	dp[0][j]=0;
	// } 

	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			// match
			if(str[i-1]==sub[j-1]){
				dp[i][j]=(dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
			}
			else dp[i][j]=dp[i-1][j];
		}
	}
	return dp[n][m];
}
