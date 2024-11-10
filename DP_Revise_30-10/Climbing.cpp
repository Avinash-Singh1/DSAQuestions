class Solution {
public:
    int f(int ind,vector<int>&dp){
        if(ind==0){
            return 1;
        }
        if(ind==1)return 1;
        if(dp[ind]!=-1) return dp[ind];
        // one step 
       int one_s= f(ind-1,dp);

        // two steps
       int two_s= f(ind-2,dp);
       
        return dp[ind]=one_s+two_s;
    }
    //tabulation
    int f_t(int n,vector<int>&dp){
       dp[0]=1;
       dp[1]=1;
       for(int ind=2;ind<=n;ind++){
         dp[ind]=dp[ind-1]+dp[ind-2];
       }
     
        return dp[n];
    }
    // space optimization
        int f_so(int n,vector<int>&dp){
            // if(n==0)return 
           int prev2=1;
           int prev=1;
            for(int ind=2;ind<=n;ind++){
                    int cur=prev2+prev;
                    prev2= prev;
                    prev = cur;
            }
     
        return prev;
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        // return f(n,dp);
        // return f_t(n,dp);
        return f_so(n,dp);
    }
};