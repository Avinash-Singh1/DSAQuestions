class Solution {
public:
    int f(int end, int start,vector<int>& nums, vector<int>&dp){
        if(end<start) return 0;
        if(end==start) return  nums[end];
          if(dp[end]!=-1) return dp[end];
        int t= nums[end]+f(end-2,start,nums,dp);
        int nt= 0+f(end-1,start,nums,dp);

        return dp[end] =max(t,nt);
    }
    int rob(vector<int>& nums) {
        int n =nums.size();
        if(n==0)return 0;
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        vector<int>dp(n+1,-1);

        int case1= f(n-2,0,nums,dp);
    fill(dp.begin(), dp.end(), -1);
        int case2= f(n-1,1,nums,dp);

        return max(case1,case2);
    }
};