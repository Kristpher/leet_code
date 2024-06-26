class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> out(rowIndex + 1);

        out[0].push_back(1);

        for (int i = 1; i <= rowIndex; i++) {
            out[i].push_back(1);

            for (int j = 1; j < i; j++) {
                out[i].push_back(out[i - 1][j - 1] + out[i - 1][j]);
            }

            out[i].push_back(1);
        }
        return out[rowIndex];
    }
};
