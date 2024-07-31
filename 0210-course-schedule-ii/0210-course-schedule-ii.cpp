class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>g(numCourses);
        vector<int>vis(numCourses,0);
        for(int i=0;i<prerequisites.size();i++){
            g[prerequisites[i][1]].push_back(prerequisites[i][0]);
            vis[prerequisites[i][0]]++;
        }
        queue<int>q;
        for(int i=0;i<vis.size();i++){
            if(vis[i]==0)
            {
                
                q.push(i);
            }

        }
        
        vector<int>out;
        int i=vis.size()-1;
        while(!q.empty()){
         
            int val=q.front();
            q.pop();
           out.push_back(val);
            for(auto i:g[val]){
                vis[i]--;
                if(vis[i]==0){
                q.push(i);
                vis[i]--;
                }
            }

        }
  return out;
    }
};