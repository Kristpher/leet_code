class Solution {
public:
    int recur(vector<int>& coins,int amount,vector<int>&dp,int m){
        if(amount<0)
        return INT_MAX;
        if(amount==0)
        return 0;
        if(dp[amount]!=-1){
            return dp[amount];
        }
        int minim=INT_MAX;
        for(int i=m;i>=0;i--){

       int val= recur(coins,amount-coins[i],dp,i);
       if(val!=INT_MAX)
       minim=min(val+1,minim);
        }
        return dp[amount]=minim;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,-1);
        sort(coins.begin(),coins.end());
        int m=coins.size()-1;
        int val=recur(coins,amount,dp,m);
        return val==INT_MAX?-1:val;
    }
};