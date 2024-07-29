class Solution {
public:
    void recur(vector<vector<int>>& matrix, vector<int>& v,
               vector<vector<int>>& vis, int m, int n,int d) {
        if (m > matrix.size() - 1 || n > matrix[0].size() - 1 || m < 0 || n < 0)
            return;
        if (v.size() == (matrix.size()) * matrix[0].size())
            return;

        if (!vis[m][n]) {
            v.push_back(matrix[m][n]);
          
        } else
            return;
        vis[m][n] = 1;
        if(d==0){
        if(n+1<=matrix[0].size()-1&&!vis[m][n+1])    
        recur(matrix, v, vis, m, n + 1,0);
        else
        recur(matrix, v, vis, m+1, n,1);
        }
              if(d==1){
        if(m+1<=matrix.size()-1&&!vis[m+1][n])    
        recur(matrix, v, vis, m+1, n,1);
        else
        recur(matrix, v, vis, m, n-1,2);
        }
              if(d==2){
        if(n-1>=0&&!vis[m][n-1])    
        recur(matrix, v, vis, m, n - 1,2);
        else
        recur(matrix, v, vis, m-1, n,3);
        }
              if(d==3){
        if(m>=0&&!vis[m-1][n])    
        recur(matrix, v, vis, m-1,n ,3);
        else
        recur(matrix, v, vis, m, n+1,0);
        }
    
        
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> v;

        vector<vector<int>> vis(m, vector<int>(n));
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                vis[i][j] = 0;
            }
        }
        recur(matrix, v, vis, 0, 0,0);
        return v;
    }
};
