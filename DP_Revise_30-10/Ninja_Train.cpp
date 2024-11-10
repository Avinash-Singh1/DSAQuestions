//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int f(int ind, int last,vector<vector<int>>& arr,vector<vector<int>>&dp){
        if(ind==0){
            int maxi =INT_MIN;
            for(int i=0;i<3;i++){
                if(i!=last){
                    int points = arr[ind][i];
                    maxi=max(maxi,points);
                }
            }
            return dp[ind][last]= maxi;
        }
        if(dp[ind][last]!=-1) return dp[ind][last];
        
        int maxPoints =INT_MIN;
        for(int i=0;i<3;i++){
            if(i!=last)
            {
                int points = arr[ind][i]+f(ind-1,i,arr,dp);
                maxPoints=max(maxPoints,points);
            }
        }
        return dp[ind][last]=maxPoints;
        
    }
    int maximumPoints(vector<vector<int>>& arr, int n) {
        // Code here
        vector<vector<int>>dp(n,vector<int>(4,-1));
        return f(n-1,3,arr,dp);
    }
};
