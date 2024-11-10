#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void f(int ind, int target, vector<int>& arr, vector<int> &ds, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(ds);
            return;
        }

        for (int i = ind; i < arr.size(); i++) {
            if (i > ind && arr[i] == arr[i - 1]) continue;
            if (arr[i] > target) break;

            ds.push_back(arr[i]);
            f(i + 1, target - arr[i], arr, ds, result);
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> ds;
        vector<vector<int>> result;
        f(0, target, candidates, ds, result);
        return result;
    }
};

int main() {
    vector<int> arr = {1, 1, 1, 2, 2};
    int target = 4;  // Set your target value here

    Solution solution;
    vector<vector<int>> result = solution.combinationSum2(arr, target);

    cout << "Combinations that sum to " << target << " are:" << endl;
    for (const auto& combination : result) {
        cout << "[";
        for (size_t i = 0; i < combination.size(); ++i) {
            cout << combination[i];
            if (i < combination.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }

    return 0;
}
