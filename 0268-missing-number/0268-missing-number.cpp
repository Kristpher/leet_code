class Solution {
public:
    int missingNumber(vector<int>& nums) {
        vector<int>v(nums.size()+1,0);
        int n=0;
        for(int i=0;i<nums.size();i++)
        {
            v[nums[i]]=1;
        }
        for(int i=0;i<=nums.size();i++)
        {
            if(v[i]==0)
            {
             n=i;
             break;
            }
        }
        return n;
    }
};