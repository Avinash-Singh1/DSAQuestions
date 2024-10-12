
#include <bits/stdc++.h>
using namespace std;

// Recursive function to calculate the maximum points for the ninja training
int f(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp) {
  if(dp[day][last]!= -1) return dp[day][last];
  if(day ==0 ){
     int maxi = INT_MIN;
     for(int i=0;i<=2;i++){
        if(i!=last){
            maxi = max(maxi,points[day][i]);
        }
     }
     return dp[day][last] = maxi;
  }

  int maxi=0;
  for(int i =0; i<=2;i++){
    if(i!=last){
        int point = points[day][i] + f(day-1,i,points,dp);
        maxi =max(maxi,point);
    }
  }

  return dp[day][last]= maxi;
}

// Function to find the maximum points for ninja training
int ninjaTraining(int n, vector<vector<int>> &points) {
  // Create a memoization table (dp) to store intermediate results
  vector<vector<int>> dp(n, vector<int>(4, -1));
  // Start the recursive calculation from the last day with no previous activity
  return f(n - 1, 3, points, dp);
}

int main() {
  // Define the points matrix
  vector<vector<int>> points = {{10, 40, 70},
                                 {20, 50, 80},
                                 {30, 60, 90}};

  int n = points.size();  // Get the number of days
  // Call the ninjaTraining function to find the maximum points and print the result
//   cout << ninjaTraining(n, points);

  // tabulation

}

// 