class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       unordered_map<string,vector<string>>map1;

        for(int i=0;i<strs.size();i++)
        {
             string temp=strs[i];
              sort(temp.begin(),temp.end());
              map1[temp].push_back(strs[i]);
        }
        vector<vector<string>>out;
        for(auto it:map1)
        {
           out.push_back(it.second);

        }
        return out;

    }
};