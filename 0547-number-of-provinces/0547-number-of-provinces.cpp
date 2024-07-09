class Solution {
public:
    void province(vector<int>& v, vector<vector<int>>& isConnected, int ind) {
       
        v[ind] = 1;

    
        for (int j = 0; j < isConnected[ind].size(); j++) {
            if (isConnected[ind][j] == 1 && v[j] == 0) {
                province(v, isConnected, j);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int> v(isConnected.size(), 0);
        int count = 0;

     
        for (int i = 0; i < isConnected.size(); i++) {
          
            if (v[i] == 0) {
                count++;
                province(v, isConnected, i);
            }
        }

        return count;
    }
};
