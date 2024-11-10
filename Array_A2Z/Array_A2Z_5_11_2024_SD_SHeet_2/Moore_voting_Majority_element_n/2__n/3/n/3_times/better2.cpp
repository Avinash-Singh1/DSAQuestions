class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n =nums.size();
        // map<int,int> mpp;
        // for(int i =0;i<n;i++){
        //     mpp[nums[i]]++;
        // }
        // for(auto it: mpp){
        //     if(it.second > nums.size()/2){
        //         return it.first;
        //     }
        // }
        // return -1;

        int cnt =0; int el =0;
        for(int i =0;i<n;i++){
            if(cnt==0){
                cnt=1;
                el = nums[i];
            }
            else if(nums[i]==el){
                cnt++;
            }
            else{
                cnt--;
            }
        }

        int cnt2=0;
        for(int i =0;i<n;i++){
           if(nums[i]==el) cnt2++;
        }
        if(cnt2 > n/2) return el;
        return -1;
    }
};