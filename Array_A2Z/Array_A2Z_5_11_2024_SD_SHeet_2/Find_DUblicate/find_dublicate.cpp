class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // brute 

        // map<int,int> mpp;
        // for(int i=0;i <nums.size();i++){
        //     mpp[nums[i]]++;
        // }

        // for(auto it: mpp){
        //     if(it.second>=2){
        //         return it.first;
        //     }
        // }
        // return -1;

       // optimal 
        int slow = nums[0];
        int fast = nums[0];
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        fast = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;

    }
};