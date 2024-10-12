#include <bits/stdc++.h>


using namespace std;

// Function to determine if
// you can reach the last index
int canJump(vector<int>& nums, int ind) {
    int n =nums.size();
    
    if(ind>=n-1) return 0;    // If we can reach the last index, return the index
    if(nums[ind]==0)return INT_MAX;
    int mini=INT_MAX;
    // tryall possible jump from curr ind
    for (int i = 1; i < nums[ind]; i++)
    { 
        int jumps= canJump(nums,ind+i);
        if (jumps != INT_MAX) {
            mini = min(mini, jumps + 1);
        }
    }
    return mini;
    
}
int canJump_op(vector<int>& nums, int ind){
    int l=0; int r=0; int n =nums.size();
    int jump=0;
    while(r<=n-1){
        int farthest =0;
        for(int i=l;i<=r;i++){
             if(i<=INT_MAX -nums[i]){
                 farthest=max(farthest,i+nums[i]) ;
             }
             else{
                farthest=INT_MAX;
             }
        }
        l=r+1;
        r= farthest; jump++;
    }
    return jump;
}

int main() {
    vector<int> nums = {4, 3, 7, 1, 2};
    
    cout << "Array representing maximum jump from each index: ";
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << " ";
    }
    cout << endl;
    
    int ans = canJump_op(nums,0);
    
   
    cout << "It is possible to reach the last index." <<ans<< endl;
 
    
    return 0;
}
                            
                        