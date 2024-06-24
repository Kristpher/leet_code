class Solution {
public:
    void recur(vector<vector<int>> &out, vector<int> &v, vector<int>& candidates, int target, int n, int sum) {
        if (sum > target)
            return;
        if (sum == target) {
            out.push_back(v);
            return;
        }

        for (int i = n; i < candidates.size(); ++i) {
          
            if (i > n && candidates[i] == candidates[i - 1])
                continue;
            v.push_back(candidates[i]);
            recur(out, v, candidates, target, i + 1, sum + candidates[i]);
            v.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> out;
        vector<int> v;
        recur(out, v, candidates, target, 0, 0);
        return out;
    }
};
