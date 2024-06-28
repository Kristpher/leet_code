class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++) {
            v[i].first = i;
            v[i].second = 0;
        }
        for (int i = 0; i < roads.size(); i++) {
            for (int j = 0; j < 2; j++) {
                int city = roads[i][j];
                v[city].second++;
            }
        }
        sort(v.begin(), v.end(),
             [](const pair<int, int>& a, const pair<int, int>& b) {
                 return a.second > b.second;
             });
        vector<int> v2(n);
        for (int i = 0; i < n; i++) {
            v2[v[i].first] = n - i;
            // cout<<v[i].first<<" "<<v[i].second<<endl;
        }
        long long sum = 0;
        for (int i = 0; i < roads.size(); i++) {
            for (int j = 0; j < 2; j++) {

                sum += v2[roads[i][j]];
            }
        }
        return sum;
    }
};