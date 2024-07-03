class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n == 0) return "";
        
        int maxlen = 1;
        int start = 0;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
            for (int j = 0; j < i; j++) {
                if ((i - j <= 2 || dp[j + 1][i - 1]) && s[i] == s[j]) {
                    dp[j][i] = true;
                    if (i - j + 1 > maxlen) {
                        maxlen = i - j + 1;
                        start = j;
                    }
                }
            }
        }
        return s.substr(start, maxlen);
    }
};
