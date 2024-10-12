class Solution {

public:

int f(int ind1,int ind2,string text1,string text2,vector<vector<int>> &dp){
    if(ind1<0 || ind2<0) return 0;
    if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
    // take 
    if(text1[ind1]==text2[ind2]){
        return dp[ind1][ind2]=1+f(ind1-1,ind2-1,text1,text2,dp);
    }
    else{
        return dp[ind1][ind2]=max(f(ind1-1,ind2,text1,text2,dp),f(ind1,ind2-1,text1,text2,dp));
    }
    
}
int longestPalindromeSubsequence(string s)
{
    // Write your code here.
    string text1 =s;
    string text2= s;
     reverse(text2.begin(),text2.end());
    int n1=text1.length();
    int n2=text1.length();
    // vector<vector<int>>dp(n1,vector<int>(n2,-1));
    //  return f(n1-1,n2-1,text1,text2,dp) ;
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
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
                             dp[ind1][ind2]= max(dp[ind1][ind2-1],dp[ind1-1][ind2]);
                        }
                }   
        }
        return ans;

}

    int minInsertions(string s) {
        int slen = s.length();
        return  (slen-longestPalindromeSubsequence(s));
    }
};