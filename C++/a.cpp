#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <numeric> // For std::gcd

// Function to compute GCD
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

class Solution {
public:
    std::vector<int> gcdValues(std::vector<int>& nums, std::vector<long long>& queries) {
        // Step 1: Count frequency of each number in nums
        std::unordered_map<int, int> frequencyMap;
        for (int num : nums) {
            frequencyMap[num]++;
        }

        // Step 2: Store all GCDs in a vector
        std::vector<int> gcdPairs;

        // Step 3: Calculate GCD for unique pairs of numbers
        for (auto it1 = frequencyMap.begin(); it1 != frequencyMap.end(); ++it1) {
            for (auto it2 = std::next(it1); it2 != frequencyMap.end(); ++it2) {
                int g = gcd(it1->first, it2->first);
                int count = it1->second * it2->second;
                for (int i = 0; i < count; ++i) {
                    gcdPairs.push_back(g);
                }
            }
        }

        // Step 4: Sort the GCD values
        std::sort(gcdPairs.begin(), gcdPairs.end());

        // Step 5: Prepare the result based on queries
        std::vector<int> result;
        for (const auto& query : queries) {
            // Handle out of range queries safely
            if (query >= 0 && query < gcdPairs.size()) {
                result.push_back(gcdPairs[query]);
            } else {
                result.push_back(-1); // Handle out-of-range queries
            }
        }

        return result;
    }
};

void runTestCase(const std::vector<int>& nums, const std::vector<long long>& queries, const std::string& caseDescription) {
    Solution sol;
    std::vector<int> result = sol.gcdValues(const_cast<std::vector<int>&>(nums), const_cast<std::vector<long long>&>(queries));

    std::cout << caseDescription << ": ";
    for (int res : result) {
        std::cout << res << " ";
    }
    std::cout << std::endl;
}

int main() {
    // Test case 1: Maximum Input Size with Same Values
    std::vector<int> nums1(100000, 10000);
    std::vector<long long> queries1 = {0}; // Reduced for demonstration
    runTestCase(nums1, queries1, "Max Input Size with Same Values");

    // Test case 2: All Primes
    std::vector<int> nums2 = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    std::vector<long long> queries2 = {0, 1}; // Adjusted for fewer queries
    runTestCase(nums2, queries2, "All Primes");

    // Test case 3: Alternating Values
    std::vector<int> nums3(100000);
    for (int i = 0; i < 100000; ++i) {
        nums3[i] = (i % 2) + 1; // Alternating between 1 and 2
    }
    std::vector<long long> queries3 = {0, 1, 2, 3, 4, 5}; // Limited number of queries
    runTestCase(nums3, queries3, "Alternating Values");

    // Test case 4: Edge Cases with GCD of 1
    std::vector<int> nums4 = {10000, 9999, 9998, 9997, 9996, 9995, 9994, 9993};
    std::vector<long long> queries4 = {0, 1, 2, 3}; // Limited number of queries
    runTestCase(nums4, queries4, "Edge Cases with GCD of 1");

    // Test case 5: Large Diverse Values
    std::vector<int> nums5(100000);
    for (int i = 0; i < 100000; ++i) {
        nums5[i] = i + 1; // An increasing sequence from 1 to 100000
    }
    std::vector<long long> queries5 = {0, 1}; // Adjusted for feasible query counts
    runTestCase(nums5, queries5, "Large Diverse Values");

    // Test case 6: Repeating Patterns with a Maximum Value
    std::vector<int> nums6(100000, 50000); // Many repeating elements
    std::vector<long long> queries6 = {0, 1}; // Adjusted for feasible query counts
    runTestCase(nums6, queries6, "Repeating Patterns with Maximum Value");

    // Test case 7: All Ones
    std::vector<int> nums7(100000, 1); // All elements are 1
    std::vector<long long> queries7 = {0}; // Adjusted for practical output
    runTestCase(nums7, queries7, "All Ones");

    // Test case 8: Mixed Values with Common GCD
    std::vector<int> nums8 = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    std::vector<long long> queries8 = {0, 1, 2, 3}; // Limited for practical output
    runTestCase(nums8, queries8, "Mixed Values with Common GCD");

    return 0;
}
