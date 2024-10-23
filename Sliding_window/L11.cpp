class Solution {
public:
    // Function to count subarrays with at most k distinct elements
    int f1(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, r = 0;
        int cnt = 0;
        map<int, int> mpp;

        while (r < n) {
            mpp[nums[r]]++;
            
            // Shrink the window if there are more than k distinct elements
            while (mpp.size() > k) {
                mpp[nums[l]]--;
                if (mpp[nums[l]] == 0) {
                    mpp.erase(nums[l]);
                }
                l++; // Corrected increment
            }
            
            // Count subarrays ending at r
            cnt += (r - l + 1);
            r++;
        }

        return cnt;
    }

    // Function to count subarrays with at most k-1 distinct elements
    int f2(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, r = 0;
        int cnt = 0;
        map<int, int> mpp;

        while (r < n) {
            mpp[nums[r]]++;
            
            // Shrink the window if there are more than k distinct elements
            while (mpp.size() > k) {
                mpp[nums[l]]--;
                if (mpp[nums[l]] == 0) {
                    mpp.erase(nums[l]);
                }
                l++; // Corrected increment
            }
            
            // Count subarrays ending at r
            cnt += (r - l + 1);
            r++;
        }

        return cnt;
    }

    // Function to count subarrays with exactly k distinct elements
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        // Using the sliding window approach, solve for at most k and at most k-1 distinct elements
        return f1(nums, k) - f1(nums, k - 1);
    }
};