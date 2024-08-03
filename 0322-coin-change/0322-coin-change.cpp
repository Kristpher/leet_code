class Solution {
public:
    int recur(vector<int>& coins, int amount, vector<int>& dp) {
        if (amount < 0)
            return INT_MAX;
        if (amount == 0)
            return 0;
        if (dp[amount] != -1) {
            return dp[amount];
        }
        
        int minim = INT_MAX;
        for (int i = 0; i < coins.size(); i++) {
            int val = recur(coins, amount - coins[i], dp);
            if (val != INT_MAX)
                minim = min(val + 1, minim); 
        }
        
        dp[amount] = minim;
        return dp[amount];
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        int val = recur(coins, amount, dp);
        return val == INT_MAX ? -1 : val;
    }
};
