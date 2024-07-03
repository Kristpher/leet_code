class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count=1;
        int p=0;
     for(int i=0;i<nums.size()-1;i++)
     {
        if(nums[i]==nums[i+1])
        count++;
        else
        count=1;
        if(count>2)
        {
         nums[i]=INT_MAX;
         p++;
        }
    }
     sort(nums.begin(),nums.end());
     return nums.size()-p;   
    }
};