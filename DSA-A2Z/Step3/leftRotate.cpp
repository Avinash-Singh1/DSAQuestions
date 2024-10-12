#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> temp(k);
        int n = nums.size();
        for (int i = 0; i < k; i++)
        {
            temp[i]=nums[i];
        }
     

        for (int i = n-k-1; i < n; i++)
        {
           nums[i-(n-k)]=nums[i];
        }
        for (int i = n-k-1; i < n; i++)
        {
            nums[i+1]=temp[i-(n-k-1)];
        }
        
        
        
    }
};

// Test the function
int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    sol.rotate(nums, k);
    
    for (int num : nums) {
        cout << num << " ";
    }
    
    return 0;
}
