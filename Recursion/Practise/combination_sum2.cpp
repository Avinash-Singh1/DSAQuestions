#include<bits/stdc++.h>

using namespace std;
class Solution {
  public:
    void findCombination(int ind, int target, vector < int > & arr, vector < vector < int >> & ans, vector < int > & ds) {
       
            if(target==0){
                ans.push_back(ds);
                return;
            }
        

        for (int i = ind; i < arr.size(); i++)
        {
            if(i>ind && arr[i]== arr[i-1]) continue;
            if(arr[i]>target) break;
            ds.push_back(arr[i]);
            findCombination(i+1,target-arr[i],arr,ans,ds);
            ds.pop_back();
        }
        
    }
  public:
    vector < vector < int >> combinationSum(vector < int > & candidates, int target) {
      vector < vector < int >> ans;
      vector < int > ds;
      sort(candidates.begin(),candidates.end());
      findCombination(0, target, candidates, ans, ds);
      return ans;
    }
};
int main() {
  Solution obj;
//   vector < int > v {1,2,3,6,7};
//   vector < int > v {2,3,6,7};
  vector < int > v {1,1,1,2,2};
  // vector < int > v {10,1,2,7,6,1,5};
  int target = 4;

  vector < vector < int >> ans = obj.combinationSum(v, target);
  cout << "Combinations are: " << endl;
  for (int i = 0; i < ans.size(); i++) {
    for (int j = 0; j < ans[i].size(); j++)
      cout << ans[i][j] << " ";
    cout << endl;
  }
}