class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> map1;
        for (int i = 0; i < nums.size(); i++) {
           
            map1[nums[i]]++;
        }
        int maxim = 0;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
        if (map1[nums[i]] > maxim) {
                maxim = map1[nums[i]];
                 count = 0;
                count++;
            }
        else if (maxim == map1[nums[i]]){
                count++;
            }
        }
        return count;
    }
};