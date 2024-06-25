class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> out;
        for (int i = 0; i < intervals.size(); ++i) {
            if (out.empty() || out.back()[1] < intervals[i][0]) {
                out.push_back(intervals[i]);
            } else {
                out.back()[1] = max(out.back()[1], intervals[i][1]);
            }
        }
        return out;
    }
};
