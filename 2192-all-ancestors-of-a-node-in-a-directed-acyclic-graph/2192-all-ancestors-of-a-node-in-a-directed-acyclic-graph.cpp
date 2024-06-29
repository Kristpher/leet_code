class Solution {
public:
    void dfs(vector<vector<int>>& graph, int source, int current, vector<vector<int>>& ancestors, vector<bool>& visited) {
        visited[current] = true;
        for (int neighbor : graph[current]) {
            if (!visited[neighbor]) {
                ancestors[neighbor].push_back(source);
                dfs(graph, source, neighbor, ancestors, visited);
            }
        }
    }
    vector<vector<int>> getAncestors(int numNodes, vector<vector<int>>& edges) {
        vector<vector<int>> ancestors(numNodes);
        vector<vector<int>> graph(numNodes);
        
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
        }
        
        for (int node = 0; node < numNodes; ++node) {
            vector<bool> visited(numNodes, false);
            dfs(graph, node, node, ancestors, visited);
        }
        
        for (int node = 0; node < numNodes; ++node) {
            sort(ancestors[node].begin(), ancestors[node].end());
        }
        
        return ancestors;
    }



};
