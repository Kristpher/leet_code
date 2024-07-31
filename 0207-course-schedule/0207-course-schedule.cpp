class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>g(numCourses);
        vector<int>vis(numCourses,0);
        for(int i=0;i<prerequisites.size();i++){
            g[prerequisites[i][0]].push_back(prerequisites[i][1]);
            vis[prerequisites[i][1]]++;
        }
        queue<int>q;
        for(int i=0;i<vis.size();i++){
            if(vis[i]==0)
            {
                q.push(i);
            }

        }
        int count=0;
        while(!q.empty()){
            int val=q.front();
            q.pop();
            count++;
            for(auto i:g[val]){
                vis[i]--;
                if(vis[i]==0){
                q.push(i);
                vis[i]--;
                }
            }

        }

        if(vis.size()==count)
        return true;
        return false;
    }
};