class Solution {
public:
    void recur(vector<int>& nums, set<vector<int>>& st, vector<int>& v, int n) {
        if (n == nums.size()) {
            sort(v.begin(), v.end());
            st.insert(v);
            return;
        }

        v.push_back(nums[n]);
        recur(nums, st, v, n + 1);
        v.pop_back();
        recur(nums, st, v, n + 1);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> st;
        vector<int> v;
        recur(nums, st, v, 0);
        vector<vector<int>> out(st.begin(), st.end());
        return out;
    }
};
