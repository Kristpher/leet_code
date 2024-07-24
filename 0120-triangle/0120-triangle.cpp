class Solution {
public:
    int recur(vector<vector<int>>& triangle, vector<vector<int>>& dp, int n, int m) {
        if (n < 0 || m < 0 || m >n)
            return INT_MAX; 

        if (n == 0 && m == 0)
            return triangle[0][0]; 

        if (dp[n][m] != -1)
            return dp[n][m];
            
        int up = recur(triangle, dp, n - 1, m);
        if (up != INT_MAX) {
            up += triangle[n][m];
        }
        
        int down = recur(triangle, dp, n - 1, m - 1);
        if (down != INT_MAX) {
            down += triangle[n][m];
        }
        
        return dp[n][m] = min(up, down);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if (n == 0) return 0;

        vector<vector<int>> dp(n);
        for (int i = 0; i < n; ++i) {
            dp[i] = vector<int>(triangle[i].size(), -1);
        }

        int minim = INT_MAX;
        for (int i = 0; i < triangle[n-1].size(); ++i) {
            minim = min(minim, recur(triangle, dp, n - 1, i));
        }

        return minim;
    }
};
