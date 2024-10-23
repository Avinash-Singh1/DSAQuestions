class Solution {
public:
     int f1(vector<int>& nums, int goal){
        if(goal<0) return 0;
        int n = nums.size();
        int r =0; int l=0; int cnt =0; int sum =0;
        while(r<n){
            sum +=(nums[r]%2);
            while(sum>goal){
                sum -= (nums[l]%2);
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
            sum += (nums[r]%2);
            while(sum>goal){
                sum -= (nums[l]%2);
                l++;
            }
            if(sum<=goal){
                cnt += r-l+1;
            }
            r++;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        int final_cnt = f1(nums,k) - f2(nums,k-1);
        return final_cnt ;
    }
};