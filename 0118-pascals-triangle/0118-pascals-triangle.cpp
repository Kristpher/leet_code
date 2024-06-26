class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> out(numRows);

        out[0].push_back(1);

        for (int i = 1; i < numRows; i++) {

            out[i].push_back(1);

            for (int j = 0; j < i - 1; j++) {
                out[i].push_back(out[i - 1][j] + out[i - 1][j + 1]);
            }

            out[i].push_back(1);
        }
        return out;
    }
};