class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int count = 0;
        if (nums.size() <= 1) {
            return 0;
        }
        
        sort(nums.begin(), nums.end());
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] <= nums[i - 1]) {
                count += (nums[i - 1] + 1 - nums[i]);
                nums[i] = nums[i - 1] + 1;
            }
        }
        
        return count;
    }
};
