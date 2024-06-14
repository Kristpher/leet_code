class Solution {
public:
    int recur(vector<int>& nums, int n, vector<int>& dp) {
        if (n < 0) {
            return 0;
        }
        if (dp[n] != -1) {
            return dp[n];
        }
        int take = nums[n] + recur(nums, n - 2, dp);
        int not_take = recur(nums, n - 1, dp);
        return dp[n] = max(take, not_take);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return nums[0];
        }
        vector<int> dp(n, -1);
        return recur(nums, n - 1, dp);
    }
};
