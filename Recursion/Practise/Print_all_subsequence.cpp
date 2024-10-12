#include <iostream>
#include <vector>

using namespace std;

// Function to perform backtracking
void print_subsequence(int ind,vector<int>& nums,vector<int>& ds, vector<vector<int>>& result,int sum,int s) {
   if(ind==nums.size()){
     if(s==sum){
        result.push_back(ds);
     }
     return;
   }
   ds.push_back(nums[ind]);
    s+=nums[ind];
   print_subsequence(ind+1,nums,ds,result,sum,s);
    s-=nums[ind];

   ds.pop_back();
   print_subsequence(ind+1,nums,ds,result,sum,s);
}

// Main function to return all subsets
vector<vector<int>> subsets(vector<int>& nums) {
   int n = nums.size();
   vector<int>ds;
   int sum =3;
   int s=0;
   vector<vector<int>> ans;
   print_subsequence(0,nums,ds,ans,sum,s);
   return ans;

}

int main() {
    vector<int> nums = {3,1,2}; // Example input
    vector<vector<int>> result = subsets(nums);

    // Print the result
    cout << "[";
    for (const auto& subset : result) {
        cout << "[";
        for (size_t i = 0; i < subset.size(); ++i) {
            cout << subset[i];
            if (i < subset.size() - 1) cout << ",";
        }
        cout << "]";
    }
    cout << "]" << endl;

    return 0;
}
