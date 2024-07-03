class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.empty()) return {};
        
        sort(nums.begin(), nums.end());
        int maxindex = 0;
        int ind = 0;
        vector<vector<int>> out(nums.size());

        for (int i = 0; i < nums.size(); i++) {
            out[i].push_back(nums[i]);
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && out[i].size() < out[j].size() + 1) {
                    out[i] = out[j];
                    out[i].push_back(nums[i]);
                }
            }
            if (maxindex < out[i].size()) {
                ind = i;
                maxindex = out[i].size();
            }
        }
        
        return out[ind];
    }
};