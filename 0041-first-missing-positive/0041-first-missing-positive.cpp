class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int l=1;
    
        unordered_map<int,int>map1;
        for(int i=0;i<nums.size();i++)
        {
           if(nums[i]>0) 
           map1[nums[i]]++;

        }
        int i=1;
        while(map1.count(i))
        {

         i++;
        }
        return i;
    }
};