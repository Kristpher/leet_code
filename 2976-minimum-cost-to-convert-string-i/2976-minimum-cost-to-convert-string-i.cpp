class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        const int INF = 1e9; 
        vector<vector<int>> dist(26, vector<int>(26, INF));
        
        for (int i = 0; i < 26; i++)
            dist[i][i] = 0;

        for (int i = 0; i < original.size(); i++) {
            if(cost[i]<dist[original[i] - 'a'][changed[i] - 'a'])
            dist[original[i] - 'a'][changed[i] - 'a'] = cost[i];
        }
       for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    if (dist[i][k] < INF && dist[k][j] < INF) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
long long sum = 0;
        for (int i = 0; i < source.length(); i++) {
            int s = source[i] - 'a';
            int t = target[i] - 'a';
            if (dist[s][t] == INF) {
                return -1; 
            }
            sum += dist[s][t];
        }
        return sum;
    }
};
