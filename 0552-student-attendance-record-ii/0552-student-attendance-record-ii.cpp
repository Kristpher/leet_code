class Solution {
    const int MOD = 1000000007;

    int countSequences(int day, int absent, int late, int n, vector<vector<vector<int>>>& dp) {
        if (day > n)
            return 1;
        if (dp[day][absent][late] != -1)
            return dp[day][absent][late];

        int addAbsent = absent < 1 ? countSequences(day + 1, absent + 1, 0, n, dp) : 0;
        int addLate = late < 2 ? countSequences(day + 1, absent, late + 1, n, dp) : 0;
        int addPresent = countSequences(day + 1, absent, 0, n, dp);

        dp[day][absent][late] = ((addAbsent + addLate) % MOD + addPresent % MOD) % MOD;
        return dp[day][absent][late];
    }

public:
    int checkRecord(int n) {
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, -1)));
        return countSequences(1, 0, 0, n, dp);
    }
};
