class Solution {
public:
    void recur(vector<vector<int>>& out, vector<int>& v, vector<int>& nums, vector<int>& freq) {
        if (v.size() == nums.size()) {
            out.push_back(v);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!freq[i]) {
                v.push_back(nums[i]);
                freq[i] = 1;
                recur(out, v, nums, freq);
                freq[i] = 0;
                v.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> out;
        vector<int> v;
        vector<int> freq(nums.size(), 0);
        recur(out, v, nums, freq);
        return out;
    }
};