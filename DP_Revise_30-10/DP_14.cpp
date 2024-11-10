#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool f(int ind, int tar, vector<int> &arr, vector<vector<int>>& dp) {
        // Base case: when the target is 0, we've found a subset
        if (tar == 0) return true;

        // If we have processed all items but not found a valid subset
        if (ind < 0) return false;

        // Check memoization
        if (dp[ind][tar] != 9) return dp[ind][tar];

        // Don't take the current element
        bool ntake = f(ind - 1, tar, arr, dp);
        
        // Take the current element if it does not exceed the target
        bool take = false;
        if (arr[ind] <= tar) {
            take = f(ind - 1, tar - arr[ind], arr, dp);
        }

        // Store the result in dp array
        return dp[ind][tar] = (ntake || take);
    }

    bool isSubsetSum(vector<int> arr, int sum) {
        int n = arr.size();
        // Initialize dp array with size (n x (sum + 1))
        vector<vector<int>> dp(n, vector<int>(sum + 1, 9));
    
        bool result=  f(n - 1, sum, arr, dp);
        for(int i=0;i<dp.size();i++){
            for (int j = 0; j < dp[0].size(); j++)
            {
                cout<<" "<<dp[i][j]<<" ";
            }
            cout<<"\n";
            
        }

        return result;

    }
};

int main() {
    // Example input
    vector<int> arr = { 2,3,1,1};
    int sum = 4;

    Solution solution;
    bool result = solution.isSubsetSum(arr, sum);

    // Output the result
    if (result) {
        cout << "Found a subset with the given sum." << endl;
    } else {
        cout << "No subset with the given sum exists." << endl;
    }

    return 0;
}
