
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int n = s.length();
        vector<bool> dp(n + 1, false);  // dp[i] indicates if s[0:i] can be segmented
        dp[0] = true;  // Base case: empty string is always "segmentable"

        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                string word = s.substr(j, i - j);  // Extract substring s[j:i]
                if (dp[j] && dict.find(word) != dict.end()) {
                    dp[i] = true;
                    break;  // No need to check further if s[0:i] can already be segmented
                }
            }
        }

        return dp[n];
    }
};

int main() {
    Solution sol;
    // string s1 = "leetcode";
    // vector<string> dict1 = {"leet", "code"};
    // cout << (sol.wordBreak(s1, dict1) ? "true" : "false") << endl;  // Output: true

    string s2 = "applepenapple";
    vector<string> dict2 = {"apple", "pen"};
    cout << (sol.wordBreak(s2, dict2) ? "true" : "false") << endl;  // Output: true

    // string s3 = "catsandog";
    // vector<string> dict3 = {"cats", "dog", "sand", "and", "cat"};
    // cout << (sol.wordBreak(s3, dict3) ? "true" : "false") << endl;  // Output: false

    return 0;
}
