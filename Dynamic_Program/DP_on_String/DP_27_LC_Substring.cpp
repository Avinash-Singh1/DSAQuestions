int lcs(string &text1, string &text2){
    // Write your code here.
          int n1 =text1.size();
        int n2= text2.size();
        // vector<vector<int>>dp(n1,vector<int>(n2,-1));
        // return f(n1-1,n2-1,text1,text2,dp);

        //space optimization -- tabulation
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
        vector<int>prev(n1+1,0);// for(int i=0;i<=n1;i++) dp[i][0]=0;
        vector<int>cur(n2+1,0);// for(int i=0;i<=n1;i++) dp[i][0]=0;
        for(int j=0;j<=n2;j++) dp[0][j]=0;
        int ans=0;
        for(int ind1=1;ind1<=n1;ind1++){
                for(int ind2=1;ind2<=n2;ind2++){
                        if(text1[ind1-1]==text2[ind2-1])  {
                            int val;
                            dp[ind1][ind2]=val = 1+ dp[ind1-1][ind2-1];
                            ans =max(ans,val);
                        }
                        else{
                             dp[ind1][ind2]= 0;
                        }
                }   
        }
        return ans;
}