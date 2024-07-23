class Solution {
public:
    static bool sor(const pair<int, string>& a, const pair<int, string>& b)
    {
        if (a.first != b.first)
            return (a.first < b.first);
        else
            return (a.second > b.second);
    }

    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int, string>> v;
        for (int i = 0; i < heights.size(); i++)
            v.push_back(make_pair(heights[i], names[i]));
        
        sort(v.begin(), v.end(), sor);
        
        for (int i = 0; i < heights.size(); i++) {
            names[i] = v[i].second;
        }
        
        return names;
    }
};