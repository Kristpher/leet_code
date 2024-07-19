class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        unordered_map<int, int> map1;
        vector<int> v;


        for (int i = 0; i < matrix.size(); i++) {
            int minim = INT_MAX;
            for (int j = 0; j < matrix[0].size(); j++) {
                minim = min(minim, matrix[i][j]);
            }
            map1[minim] = 1;
        }

       
        for (int j = 0; j < matrix[0].size(); j++) {
            int maxim = -1;
            for (int i = 0; i < matrix.size(); i++) {
                maxim = max(maxim, matrix[i][j]);
            }
            if (map1.count(maxim)) {
                v.push_back(maxim);
            }
        }

        return v;
    }
};
