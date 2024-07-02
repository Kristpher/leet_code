class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> map1;
        int i = 0, j = 0;
        int maxim = 0;

        while (j < nums.size()) {
            map1[nums[j]]++;
            while (map1[nums[j]] > k) {
                map1[nums[i]]--;
                i++;
            }
            maxim = max(j - i + 1, maxim);
            j++;
        }

        return maxim;
    }
};
