class Solution {
public:
    int findTheWinner(int n, int k) {
        std::vector<int> v;
        for (int i = 0; i < n; ++i)
            v.push_back(i + 1);

        int start = 0;
        while (v.size() > 1) {
            start = (start + k - 1) % v.size();  
            v.erase(v.begin() + start); 
        }
        return v[0];
    }
};