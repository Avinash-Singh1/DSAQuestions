#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
         // Utilize a map to count GCD frequencies.
        std::unordered_map<int, int> gcdCount;
        long long n = nums.size();
        
        // Calculate the GCD for all pairs.
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                gcdCount[std::__gcd(nums[i], nums[j])]++;
            }
        }
        
        // Prepare a sorted list of GCD results.
        std::vector<int> gcdPairs;
        for (const auto& pair : gcdCount) {
            for (int count = 0; count < pair.second; count++) {
                gcdPairs.push_back(pair.first);
            }
        }

        std::sort(gcdPairs.begin(), gcdPairs.end());
        
        // Prepare the result based on queries.
        std::vector<int> answer(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            answer[i] = gcdPairs[queries[i]];
        }
        
        return answer;
    }
};