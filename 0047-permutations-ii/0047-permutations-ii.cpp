#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void recur(vector<vector<int>>& out, vector<int>& v, vector<int>& nums, vector<bool>& freq) {
        if (v.size() == nums.size()) {
            out.push_back(v);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!freq[i]) {
               
                if (i > 0 && nums[i] == nums[i - 1] && !freq[i - 1]) {
                    continue;
                }
                v.push_back(nums[i]);
                freq[i] = true;
                recur(out, v, nums, freq);
                freq[i] = false;
                v.pop_back();
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> out;
        vector<int> v;
        vector<bool> freq(nums.size(), false);
        sort(nums.begin(), nums.end()); 
        recur(out, v, nums, freq);
        return out;
    }
};
