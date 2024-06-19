class Solution {
public:
 int recur(vector<int>& nums,vector<int>& dp,int n)
 {
    
    if(n>=nums.size()-1)
    {
        return 1;
    }
     if(nums[n]==0)
    return 0;
   

    if(dp[n]!=-1)
    return dp[n];
    int maxim=0;
    for(int i=1;i<=nums[n];i++){
    int left=recur(nums,dp,n-i)+1;
    maxim=max(left,maxim);
    }
    return dp[n]=maxim;
 }
    int jump(vector<int>& nums) {
   if(nums.size()==1)
   return 0;
   vector<int>dp(nums.size(),-1);

    return recur(nums,dp,0);     
    }
};