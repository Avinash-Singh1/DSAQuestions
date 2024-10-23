class Solution {
public:
    int f1(vector<int>& nums, int goal){
        if(goal<0) return 0;
        int n = nums.size();
        int r =0; int l=0; int cnt =0; int sum =0;
        while(r<n){
            sum += nums[r];
            while(sum>goal){
                sum -= nums[l];
                l++;
            }
            if(sum<=goal){
                cnt += r-l+1;
            }
            r++;
        }
        return cnt;
    }
    int f2(vector<int>& nums, int goal){
        if(goal<0) return 0;
        int n = nums.size();
        int r =0; int l=0; int cnt =0; int sum =0;

        while(r<n){
            sum += nums[r];
            while(sum>goal){
                sum -= nums[l];
                l++;
            }
            if(sum<=goal){
                cnt += r-l+1;
            }
            r++;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int final_cnt = f1(nums,goal) - f2(nums,goal-1);
        return final_cnt ;
    }
};