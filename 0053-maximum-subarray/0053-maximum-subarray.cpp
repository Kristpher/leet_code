class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0], maxim = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            sum = max(nums[i], sum + nums[i]);
            maxim = max(maxim, sum);
        }
        return maxim;
    }
};
