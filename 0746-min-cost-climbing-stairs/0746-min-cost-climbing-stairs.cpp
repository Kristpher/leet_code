class Solution {
public:
int recur(vector<int>& cost,vector<int>& dp,int n){
    if(n==0 ||n==1)
    {
        return cost[n];
    }
    if(dp[n]!=-1)
    return dp[n];
    int one=recur(cost,dp,n-1)+cost[n];
    int two=recur(cost,dp,n-2)+cost[n];
    return dp[n]=min(one,two);


}
    int minCostClimbingStairs(vector<int>& cost) {
     vector<int>dp(cost.size()+1,-1);
     int n=cost.size();
    
     cost.push_back(0);
  
     return recur(cost,dp,n);
    }
};