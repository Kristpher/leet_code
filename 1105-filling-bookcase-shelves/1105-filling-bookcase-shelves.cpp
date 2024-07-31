class Solution {
public:
    int recur(vector<vector<int>>& books, int s, int ind, vector<int>& dp) {
        if (ind == books.size())
            return 0;
        if (dp[ind] != -1)
            return dp[ind];

        int width = 0;
        int height = 0;
        int minHeight = INT_MAX;

        for (int i = ind; i < books.size(); ++i) {
            if (width + books[i][0] > s)
                break;
            width += books[i][0];
            height = max(height, books[i][1]);
            minHeight = min(minHeight, height + recur(books, s, i + 1, dp));
        }

        return dp[ind] = minHeight;
    }

    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        vector<int> dp(books.size(), -1);
        return recur(books, shelfWidth, 0, dp);
    }
};
