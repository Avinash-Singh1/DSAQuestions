#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int countElementsWithMaxFrequency(const std::vector<int>& nums) {
        std::unordered_map<int, int> frequencyMap;

        // Count frequency of each element
        for (int num : nums) {
            frequencyMap[num]++;
        }

        // Find the maximum frequency
        int maxFrequency = 0;
        for (const auto& pair : frequencyMap) {
            maxFrequency = std::max(maxFrequency, pair.second);
        }

        // Count the number of elements with the maximum frequency
        int countMaxFrequency = 0;
        for (const auto& pair : frequencyMap) {
            if (pair.second == maxFrequency) {
                countMaxFrequency += pair.second;
            }
        }

        return countMaxFrequency;
    }
};

int main() {
    Solution sol;
    std::vector<int> nums1 = {1, 2, 2, 3, 1, 4};
    std::vector<int> nums2 = {1, 2, 3, 4, 5};

    std::cout << "Total frequencies with the maximum frequency in nums1: " 
              << sol.countElementsWithMaxFrequency(nums1) << std::endl;
    std::cout << "Total frequencies with the maximum frequency in nums2: " 
              << sol.countElementsWithMaxFrequency(nums2) << std::endl;

    return 0;
}
