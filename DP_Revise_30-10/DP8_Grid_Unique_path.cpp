class Solution {
public:
    int helper(int i ,int j,vector<vector<int>>& dp){
        if(i==0 && j==0) return 1;
        if(i<0 ||j<0)return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int up =helper(i-1,j,dp);
        int left =helper(i,j-1,dp);
        return dp[i][j]= up+left;
    }
    int spaceoptimization(int m,int n){
        vector<int>prev(n,0);
        for(int i=0;i<m;i++){
             vector<int>temp(n,0);
            for(int j=0;j<n;j++){

                if(i==0 && j==0){
                    temp[j]=1;
                    continue;
                }

                else{
                    int up =0; int left =0;
                    if(i>0) up =prev[j];
                    if(j>0) left =temp[j-1];
                    temp[j]=up+left;
                }
            }
            prev =temp;
        }
        return prev[n-1];
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        // return helper(n-1,m-1,dp);

        //tabulation
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         if(i==0 && j==0){
        //             dp[0][0]=1;
        //             continue;
        //         }
        //             // Initialize variables to store the number of ways from the cell above (up) and left (left).
        //         int up = 0;
        //         int left = 0;

        //         // If we are not at the first row (i > 0), update 'up' with the value from the cell above.
        //         if (i > 0)
        //             up = dp[i - 1][j];
        //         // If we are not at the first column (j > 0), update 'left' with the value from the cell to the left.
        //         if (j > 0)
        //         left = dp[i][j - 1];

        //         dp[i][j]= up+left;
        //     }
        // }
        // return dp[m-1][n-1];
        // tabulation ends here

        // space start 
        return spaceoptimization(m,n);
        // space ends
    }
};