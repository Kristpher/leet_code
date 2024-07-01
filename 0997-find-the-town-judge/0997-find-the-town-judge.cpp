class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if (n == 1)
            return 1;

        vector<int> trustCounts(n + 1, 0);
        vector<int> trustedBy(n + 1, 0); 

        for (int i = 0; i < trust.size(); i++) {
            trustCounts[trust[i][0]]++;
            trustedBy[trust[i][1]]++;
        }

        for (int i = 1; i <= n; i++) {
           
            if (trustCounts[i] == 0 && trustedBy[i] == n - 1) {
                return i;
            }
        }

        return -1; 
    }
};
