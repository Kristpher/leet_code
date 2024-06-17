class Solution {
public:
    int recur(int n,vector<int>&dp)
    {
        if(n<=1)
        return 1;
        if(dp[n]!=-1)
        return dp[n];
        int one=recur(n-1,dp);
        int two=recur(n-2,dp);
        return dp[n]=one+two;
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
    return recur(n,dp);
    }
};