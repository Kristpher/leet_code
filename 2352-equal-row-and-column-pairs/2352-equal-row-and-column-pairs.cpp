class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<string, int> rowMap;
        int n = grid.size();

        // Count row occurrences
        for (int i = 0; i < n; i++) {
            string num = "";
            for (int j = 0; j < n; j++) {
                num += to_string(grid[i][j]) + ",";
            }
            rowMap[num]++;
        }


        int comb = 0;
        for (int i = 0; i < n; i++) {
            string num = "";
            for (int j = 0; j < n; j++) {
                num += to_string(grid[j][i]) + ",";
            }
            if (rowMap.find(num) != rowMap.end()) {
                comb += rowMap[num];
            }
        }

        return comb;
    }
};
