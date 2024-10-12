                            
#include <vector>   
#include <algorithm>
#include <iostream>

using namespace std;

// Function to determine if
// you can reach the last index
bool canJump(vector<int>& nums) {
   int maxR=0;
   int n = nums.size();
   for(int i =0;i<n;i++){
        if(i>maxR) return false;
        maxR=max(maxR,i+nums[i]);
        if(maxR>=n-1) return true;
   }
   return true;
}

int main() {
    vector<int> nums = {4, 3, 7, 1, 2};
    // vector<int> nums = { 3, 2,1,0,4}; // return false;

    
    cout << "Array representing maximum jump from each index: ";
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << " ";
    }
    cout << endl;
    
    bool ans = canJump(nums);
    
    if (ans) {
        cout << "It is possible to reach the last index." << endl;
    } else {
        cout << "It is not possible to reach the last index." << endl;
    }
    
    return 0;
}
                            
                        