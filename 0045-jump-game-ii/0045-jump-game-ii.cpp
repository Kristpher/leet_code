class Solution {
public:
    int recur(vector<int>& nums, vector<int>& dp, int n) {
        if (n >= nums.size() - 1) {
            return 0; 
        }
        if (nums[n] == 0) {
            return INT_MAX;
        }

        if (dp[n] != -1) {
            return dp[n];
        }

        int minJumps = INT_MAX;
        for (int i = 1; i <= nums[n]; ++i) {
            int result = recur(nums, dp, n + i);
            if (result != INT_MAX) { 
                minJumps = min(minJumps, result + 1);
            }
        }

        dp[n] = minJumps;
        return dp[n];
    }

    int jump(vector<int>& nums) {
        if (nums.size() == 1) {
            return 0;
        }
        vector<int> dp(nums.size(), -1);
        return recur(nums, dp, 0);
    }
};
