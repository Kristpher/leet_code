class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>map1;
        int val=0;
        for(int i=0;i<nums.size();i++)
        map1[nums[i]]++;
        for(int i=0;i<nums.size();i++)
        {
            if(map1[nums[i]]>floor(nums.size()/2)){
           
            val=i;
            }
        }
        return nums[val];
    }
};