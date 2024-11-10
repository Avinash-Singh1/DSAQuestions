class Solution {
public:
    void f(int ind,vector<int> arr,set<vector<int>>&result,vector<int>&ds){
        if(ind==arr.size()){
            sort(ds.begin(), ds.end());
            result.insert(ds);
            return;
        }
        
        //take 
        ds.push_back(arr[ind]);
        f(ind+1,arr,result,ds);
        // not take
        ds.pop_back();
        f(ind+1,arr,result,ds);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>ds;
        set<vector<int>>result;
        vector<vector<int>>ans;
        f(0,nums,result,ds);
        for (auto it = result.begin(); it != result.end(); it++) {
         ans.push_back( * it);
        }

       return ans;

    }  
};