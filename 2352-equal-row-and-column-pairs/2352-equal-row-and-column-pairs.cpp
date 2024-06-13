class Solution {
public:
 

    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<string, int> rowMap;
        unordered_map<string, int> colMap;
        int n = grid.size();

        for (int i = 0; i < n; i++) {
            string num = "";
            for (int j = 0; j < n; j++) {
                num += to_string( grid[i][j]);
            }
            rowMap[num]++;
        }

   
        for (int i = 0; i < n; i++) {
             string num1 = "";
            for (int j = 0; j < n; j++) {
                num1 += to_string( grid[j][i]);
            }
          
            colMap[num1]++;
        }

     
        int comb = 0;
        for (const auto& [key, value] : rowMap) {
            if (colMap.find(key) != colMap.end()) {
                comb += value * colMap[key];
            }
        }

        return comb;
    }
};
