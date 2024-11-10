class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l =0; int r= 0; int n =nums.size();
        int maxlen=0;
        int zeros=0;

        while(r<n){
            if(nums[r]==0) zeros++;
            if(zeros>k){
                if(nums[l]==0) zeros--;
                l++;
            }
            if(zeros<=k){
                int len = r-l+1;
                maxlen= max(maxlen,len);
            }

            r++;
        }
        return maxlen;
    }
};

// brute 
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int totalFruits(vector<int> &arr) {
        int n = arr.size();
        int maxlen =0;
        for(int i=0; i<n;i++){
            set<int> st;
            for(int j=i;j<n;j++){
                st.insert(arr[j]);
                if(st.size()<=2){
                    int len =j-i+1;
                    maxlen =max(maxlen,len);
                }
                else{
                    break;
                }
            }
        }
        
        return maxlen;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore any newline character left in the buffer
    while (t--) {
        string line;
        getline(cin, line); // Read the entire line of input
        stringstream ss(line);
        vector<int> arr;
        int num;

        // Parse the input line into integers and add to the vector
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        int ans = ob.totalFruits(arr);

        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends