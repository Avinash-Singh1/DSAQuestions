#include <bits/stdc++.h> 
int f(int ind,int transactionNo,vector<int> &prices,int n,int k){
    if(ind ==n || transactionNo==2*k)return 0;
    if(transactionNo%2==0)  // buy
    {
        return max(-prices[ind]+f(ind+1,transactionNo+1,prices,n,k),0+f(ind+1,transactionNo,prices,n,k));
    }
    else{
        return max(prices[ind]+f(ind+1,transactionNo+1,prices,n,k),0+f(ind+1,transactionNo,prices,n,k));
    }
}
int maximumProfit(vector<int> &prices, int n, int k)
{
    // Write your code here.
    // params
    // index, transaction
    return f(0,0,prices,n,k);
}
