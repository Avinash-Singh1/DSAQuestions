class Solution {
public:
    void generatePermutations(std::vector<int>& arr, int start, std::vector<std::vector<int>>& result) {
    // Base case: if we reach the end, add the permutation to result
    if (start >= arr.size()) {
        result.push_back(arr);  // Store the current permutation
        return;
    }

    // Recursive case: swap each element with the start and permute the rest
    for (int i = start; i < arr.size(); i++) {
        std::swap(arr[start], arr[i]);         // Swap current element with the start
        generatePermutations(arr, start + 1, result);  // Recurse for the rest
        std::swap(arr[start], arr[i]);         // Backtrack (undo the swap)
    }
}
    void nextPermutation(vector<int>& nums) {
          sort(nums.begin(), nums.end());
          vector<vector<int>> result;  // Vector to store all permutations
          generatePermutations(nums, 0, result);
        auto it = std::find(result.begin(), result.end(), nums);

            if (it != result.end() && it + 1 != result.end()) {
            // Print the next permutation
            for (int num : *(it + 1)) {
                std::cout << num << " ";
            }
            std::cout << std::endl;
        } else {
            
            for (int num : result[0]) {
                std::cout << num << " ";
            }
            std::cout << std::endl;
        }
    }
};