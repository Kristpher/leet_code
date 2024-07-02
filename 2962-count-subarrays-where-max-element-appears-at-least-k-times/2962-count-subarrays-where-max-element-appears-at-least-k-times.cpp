class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxim = 0;
        long long val = 0;

        for (int i = 0; i < nums.size(); i++) {
            maxim = max(maxim, nums[i]);
        }

        int i = 0, j = 0;
        int count = 0;

        while (j < nums.size()) {
            if (nums[j] == maxim) {
                count++;
            }

            while (count >= k) {
                val += nums.size() - j;  
                if (nums[i] == maxim) {
                    count--;
                }
                i++;
            }

            j++;
        }

        return val;
    }
};
