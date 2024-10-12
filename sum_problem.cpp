#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        
        // Start from the last digit
        for (int i = n - 1; i >= 0; --i) {
            // Increment current digit and check for carry
            if (digits[i] < 9) {
                digits[i] += 1;
                return digits; // No carry, return incremented digits
            } else {
                digits[i] = 0; // Carry over to next more significant digit
            }
        }
        
        // If we are here, it means there was a carry over to the most significant digit
        digits.insert(digits.begin(), 1);
        
        return digits;
    }
};

int main() {
    Solution solution;
    
    // Example usage:
    vector<int> digits1 = {1, 2, 3};
    vector<int> result1 = solution.plusOne(digits1);
    cout << "Result 1: ";
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;
    
    vector<int> digits2 = {4, 3, 2, 1};
    vector<int> result2 = solution.plusOne(digits2);
    cout << "Result 2: ";
    for (int num : result2) {
        cout << num << " ";
    }
    cout << endl;
    
    vector<int> digits3 = {6,8,5,9};
    vector<int> result3 = solution.plusOne(digits3);
    cout << "Result 3: ";
    for (int num : result3) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
