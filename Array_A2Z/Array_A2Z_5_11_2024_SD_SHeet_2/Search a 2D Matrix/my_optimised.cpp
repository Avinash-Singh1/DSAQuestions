class Solution {
public:
  bool binarySearch(vector<int>& nums, int target) {
    int n = nums.size();
    int low =0; int high = n-1;

    while(low<=high){
        int mid = low+(high-low)/2;
        if(nums[mid]== target) return true;
        if(nums[mid] < target){
            low =mid+1;
        }
        else{
            high= mid-1;
        }
    }
    return false;
  }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // brute 
        int n = matrix.size();
        int m = matrix[0].size();
        // for(int i=0;i<n;i++){
        //    if(matrix[i][0] <= target && target <= matrix[i][n-1]){
        //         return binarySearch(matrix[i],target);      
        //    }
        // }
        // return false;

        // optimal
        int low =0; int high= (n*m-1);
        while(low<=high){
            int mid= low+(high-low)/2;
            int row= mid/m;
            int col= mid%m;
            if(matrix[row][col]== target) return true;
            else if(matrix[row][col] < target){
                low =mid+1;
            }
            else{
                high= mid-1;
            }
        }
        return false;
    }
};