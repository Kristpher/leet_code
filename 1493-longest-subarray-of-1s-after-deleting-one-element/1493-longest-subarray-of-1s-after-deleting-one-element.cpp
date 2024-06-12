class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int start=0;
        int end=nums.size();
        int maxim=0;
        int p=0;
        int mid=0;
        while(start<end)
        {
            if(nums[start]==0)
            p++;
            if(p>1)
            {
                if(nums[mid]==0)
                p--;
                mid++;
            }
            maxim=max(maxim,start-mid);
            start++;

        }
        return maxim;
    }
};