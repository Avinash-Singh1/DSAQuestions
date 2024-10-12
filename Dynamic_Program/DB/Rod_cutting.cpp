// GFG
class Solution{
  public:
    int  helper(int ind,int len,int price[],vector<vector<int>>& dp){
        if (len <= 0) {
            return 0;
        }
        if(ind==0){
            return len*price[ind];
        }
        if(dp[ind][len]!=-1)return dp[ind][len];
        int nt= 0+helper(ind-1, len,price,dp);
        int t=INT_MIN;
        int rodlen=ind+1;
        if(rodlen<=len) t=price[ind]+helper(ind, len-rodlen,price,dp);
        return dp[ind][len]= max(t,nt);
    }
    int cutRod(int price[], int n) {
        //code here
        // vector<vector<int>> dp(n-1,vector<int(n,-1));
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        int ind= n-1; int len=n;
        return helper(ind,len,price,dp);
        
        //tabulation
        
    }
};