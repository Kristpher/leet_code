class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> map1;
        vector<vector<int>> v(2);
        for (int i = 0; i < nums1.size(); i++) {
            map1[nums1[i]] = 1;
        }
        for (int i = 0; i < nums2.size(); i++) {

            if (map1[nums2[i]] == 1) {
                map1[nums2[i]] = 2;
                continue;
            }
            if (map1[nums2[i]] == 2)
                continue;
            map1[nums2[i]] = 3;
        }

        for (int i = 0; i < max(nums2.size(), nums1.size()); i++) {
            if (i < nums1.size()) {
                if (map1[nums1[i]] == 1) {
                    v[0].push_back(nums1[i]);
                    map1[nums1[i]] = 0;
                }
            }
            if (i < nums2.size()) {
                {
                    if (map1[nums2[i]] == 3) {
                        v[1].push_back(nums2[i]);
                        map1[nums2[i]] = 0;
                    }
                }
            }
        }
        return v;
    }
};