class Solution {
public:
    int check(int i, int j, int val, vector<vector<int>>& board) {
        int liveNeighbors = 0;
        int directions[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

        for (auto& dir : directions) {
            int newRow = i + dir[0];
            int newCol = j + dir[1];
            if (newRow >= 0 && newRow < board.size() && newCol >= 0 && newCol < board[0].size()) {
                liveNeighbors += board[newRow][newCol];
            }
        }

        return liveNeighbors;
    }

    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> temp(board.size(), vector<int>(board[0].size()));
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                int live = check(i, j, board[i][j], board);
                if (board[i][j] == 1) {
                    temp[i][j] = (live == 2 || live == 3) ? 1 : 0;
                } else {
                    temp[i][j] = (live == 3) ? 1 : 0;
                }
            }
        }
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                board[i][j] = temp[i][j];
            }
        }
    }
};
