class Solution {
public:
    void dfs(int ind,vector<int>&v,vector<vector<int>>& rooms){
        v[ind]=1;
        for(auto val:rooms[ind])
        {
            if(!v[val])
            dfs(val,v,rooms);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int>v(rooms.size(),0);
        dfs(0,v,rooms);
        for(int i=0;i<rooms.size();i++)
        {
           if(!v[i])
           return false;
        }
        return true;
    }
};