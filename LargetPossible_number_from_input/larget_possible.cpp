class Solution {
public:
    string largestNumber(vector<int>& nums) {
                vector<string> str_nums;
        for (int i = nums.size() - 1; i >= 0; i--) {
            str_nums.push_back(to_string(nums[i]));
        }

        // Sort using custom comparator
        sort(str_nums.begin(), str_nums.end(), compare);

        // Handle edge case where the largest number is "0"
        if (str_nums[0] == "0") {
            return "0";
        }

        // Concatenate all strings
        string result;
        for (const string &s : str_nums) {
            result += s;
        }

        return result;
    }
   private:
    static bool compare(const string &a, const string &b) {
        return a + b > b + a;
    }


};