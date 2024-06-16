class Solution {
public:
    bool check(int n, int row, int col, vector<string>& temp) {
      
        for (int i = 0; i < row; ++i) {
            if (temp[i][col] == 'Q') return false;
        }

    
        for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
            if (temp[i][j] == 'Q') return false;
        }


        for (int i = row, j = col; i >= 0 && j < n; --i, ++j) {
            if (temp[i][j] == 'Q') return false;
        }

        return true;
    }

    void nqueen(int n, int row, vector<string>& temp, vector<vector<string>>& chess) {
        if (row == n) {
            chess.push_back(temp);
            return;
        }
        for (int col = 0; col < n; ++col) {
            if (check(n, row, col, temp)) {
                temp[row][col] = 'Q';
                nqueen(n, row + 1, temp, chess);
                temp[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> chess;
        vector<string> temp(n, string(n, '.'));
        nqueen(n, 0, temp, chess);
        return chess;
    }
};
