class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int m = rowSum.size();
        int n = colSum.size();
        vector<vector<int>> matrix(m, vector<int>(n, 0));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int minValue = min(rowSum[i], colSum[j]);
                matrix[i][j] = minValue;
                rowSum[i] -= minValue;
                colSum[j] -= minValue;
            }
        }
        
        return matrix;
    }
};
