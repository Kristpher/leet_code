class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> map1;
        for (int i = 0; i < nums.size(); i++) {
            map1[nums[i]] = 1;
        }
        int j = 0;
        int k = 0;
        int maxim = 0;
        int l = 0;
        for (int i = 0; i < nums.size(); i++) {
            l = 0;
            if (map1[nums[i]] == 1) {
                j = nums[i] + 1;
                k = nums[i] - 1;

                while (map1[j] == 1) {
                       map1[j] = 0;
                    j++;
                 
                    l++;
                }
                //cout<<l<<" ";
                while (map1[k] == 1) {
                    map1[k] = 0;
                    k--;
                   
                    l++;
                }
               // cout<<l<<" ";
                map1[nums[i]] = map1[nums[i]] + l;
            }
            maxim = max(map1[nums[i]], maxim);
        }
        return maxim;
    }
};