class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int currentFlips = 0;
        int flipCount = 0;
        vector<int> flipIndicator(n, 0);
        for (int i = 0; i < n; ++i) {
            if (i >= k) {
                currentFlips ^= flipIndicator[i - k];
            }
            if (currentFlips == nums[i]) {
                if (i + k > n) {
                    return -1;
                }
                flipIndicator[i] = 1;
                currentFlips ^= 1;
                flipCount++;
            }
        }
        return flipCount;
    }
};
