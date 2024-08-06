class Solution {
public:
    static bool comp(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }

    int minimumPushes(string word) {
        vector<pair<int, int>> v(26, make_pair(0, 0));
        for (int i = 0; i < 26; i++) {
            v[i].first = i;
            v[i].second = 0;
        }
        for (int i = 0; i < word.length(); i++) {
            v[word[i] - 'a'].second++;
          
        }
        sort(v.begin(), v.end(), comp);
        int count = 0;
        int press = 0;
        int val = 1;
        for (int i = 0; i < 26; i++) {
            if (v[i].second == 0)
                break;
            press += val*v[i].second;
            count++;
            if (count == 8) {
                val++;
                count = 0;
            }
        }
        return press;
    }
};