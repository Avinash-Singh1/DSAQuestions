class Solution{
  public:
    int f(int ind,int len,int prices[],vector<vector<int>> &dp){
        
        if(len<=0)return 0;
        if(ind==0){
            return (len* prices[0]);
        } 
        
        if(dp[ind][len]!=-1)return dp[ind][len];
        //notake
        int rodlen= ind+1;
        int nt = 0+f(ind-1,len,prices,dp);
        
        //take
        int t= INT_MIN;
        if(rodlen<=len) t =prices[ind]+f(ind,len-rodlen,prices,dp);
        
        return dp[ind][len]= max(nt,t);
    }
    int cutRod(int prices[], int n) {
        //code here
        // vector<vector<int>>dp(n,vector<int>(n+1,-1));
        // return f(n-1,n,prices,dp);
        
        // tabulation 
        vector<vector<int>>dp(n,vector<int>(n+1,0));
        for(int len =0;len<=n;len++){
            dp[0][len]= (len* prices[0]);
        }
        
        for(int ind =1;ind<n;ind++){
            for(int len=0;len<=n;len++){
                    int rodlen = ind + 1;
        int nt = dp[ind - 1][len];  // No-take case: not using current piece

                // Take case: use current piece if it's smaller than or equal to the remaining length
                int t = INT_MIN;
                if (rodlen <= len) {
                    t = prices[ind] + dp[ind][len - rodlen];
                }
        
                // Maximize between taking or not taking the current piece
                dp[ind][len] = max(nt, t);
            }
        }
        return dp[n-1][n];
    }
};