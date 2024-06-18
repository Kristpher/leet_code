class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int>store(nums.size());
        for(int i=0;i<nums.size();i++)
        {
            store[(i+k)%nums.size()] = nums[i];
        }
        for(int i=0;i<nums.size();i++){
            nums[i]=store[i];
        }
    }
};