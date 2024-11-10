class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int l =n-1;
        int r = 0;
        int k  =n+m-1;


        while(l >=0 && r  < m){
            if(nums1[l]>nums2[r]){
                swap(nums1[l],nums2[r]);
                l--;
                r++;
            }
            else{
                break;
            }
        }
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());

        

    }
};