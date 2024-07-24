class Solution {
public:
    int recur(vector<int>& nums,vector<int>& dp,int n){
        if(n<0)
        return 0;
        int two=recur(nums,dp,n-2)+nums[n];
        int one=recur(nums,dp,n-1);
        return dp[n]=max(one,two);
    }
    int rob(vector<int>& nums) {
         if(nums.size()==0)
         return 0;
         if(nums.size()==1)
         return nums[0];
        vector<int>dp(nums.size(),-1);
        return recur(nums,dp,nums.size()-1);
    }
};