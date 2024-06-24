class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>>temp(matrix.begin(),matrix.end());
        for(int i=matrix.size()-1;i>=0;i--)
        {
            for(int j=0;j<matrix.size();j++)
            {
                matrix[j][matrix.size()-1-i]=temp[i][j];
            }
        }
    }
};