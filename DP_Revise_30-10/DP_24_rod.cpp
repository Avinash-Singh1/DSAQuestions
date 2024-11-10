class Solution{
  public:
    int f(int ind,int len,int price[],vector<vector<int>>&dp){
        if(len==0) return 0;
        if(ind==0) {
                return len*price[ind];
        }
        
        if(dp[ind][len]!=-1)return  dp[ind][len];
        
        int nt =0+ f(ind-1,len,price,dp);
        
        int t = INT_MIN;
        if(ind+1 <= len)  t = price[ind] + f(ind, len - (ind + 1), price, dp);

        return dp[ind][len] =max(nt,t);
    }
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return f(n-1,n,price,dp);
    }
};