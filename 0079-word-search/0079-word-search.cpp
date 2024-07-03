class Solution {
public:
    bool back(vector<vector<char>>& board, string word, int m, int n, int i) {
        if (i == word.size()) {
            return true;
        }
        if (m < 0 || m >= board.size() || n < 0 || n >= board[0].size() || board[m][n] != word[i]) {
            return false;
        }
        
        char temp = board[m][n]; 
        board[m][n] = '.'; 

        bool found = back(board, word, m + 1, n, i + 1) ||
                     back(board, word, m - 1, n, i + 1) ||
                     back(board, word, m, n + 1, i + 1) ||
                     back(board, word, m, n - 1, i + 1);

        board[m][n] = temp; 
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for (int m = 0; m < board.size(); ++m) {
            for (int n = 0; n < board[0].size(); ++n) {
                if (back(board, word, m, n, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};
