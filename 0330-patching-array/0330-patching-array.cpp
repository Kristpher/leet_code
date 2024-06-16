class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long minp=0;
        long long maxsum=0;
        int i=0;
        while(maxsum<n)
        {
            if(i<nums.size() && maxsum+1>=nums[i])
            {
                maxsum+=nums[i];
                i++;
            }
            else{
            minp++;
maxsum+=(maxsum+1);
            }
        }
        return minp;
    }
};