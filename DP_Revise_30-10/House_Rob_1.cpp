class Solution {
public:
     int f(int ind,vector<int>& arr,vector<int>&dp)
    {
             if(ind==0) return arr[ind];
             if(ind<0) return 0;

             if(dp[ind]!=-1) return dp[ind];
             int take =arr[ind] +f(ind-2,arr,dp);
             // not take
             int ntake =0+ f(ind-1,arr,dp);

             return dp[ind]= max(take,ntake);
    }
    int rob(vector<int>& nums) {
        int n =nums.size();
        vector<int>dp(n,-1);
        return f(n-1,nums,dp);
    }
};