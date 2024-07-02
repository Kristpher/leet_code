class Solution {
public:
 int recur(vector<int>& prices,vector<vector<vector<int>>>&dp,int n,int b,int c) {

        if(n==prices.size()||c==0) return 0;
        if(dp[n][b][c]!=-1) return dp[n][b][c];
        int profit=0;
        if(b)
        profit=max(-prices[n]+recur(prices,dp,n+1,!b,c),recur(prices,dp,n+1,b,c));
        else
        profit=max(prices[n]+recur(prices,dp,n+1,!b,c-1),recur(prices,dp,n+1,b,c));
        return dp[n][b][c]=profit;
       
    }
    int maxProfit(vector<int>& prices) {
     vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(3,-1)));

        return recur(prices,dp,0,1,2); 
    }
};