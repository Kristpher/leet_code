class Solution {
public:
    int recur(vector<int>& cost,int n,vector<int>& dp){
        if(n==0||n==1)
        return 0;
        if(dp[n]!=-1)
        return dp[n];
        int one=recur(cost,n-1,dp)+cost[n-1];
        int two=recur(cost,n-2,dp)+cost[n-2];
        return dp[n]=min(one,two);
    }
    int minCostClimbingStairs(vector<int>& cost) {
     vector<int>dp(cost.size()+1,-1);
     return recur(cost,cost.size(),dp);    
    }

};